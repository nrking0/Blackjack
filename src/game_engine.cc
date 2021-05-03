#include "game_engine.h"


namespace blackjack {

GameEngine::GameEngine() {
    current_turn_ = Turn::HOME_SCREEN;
    num_players_ = 0;
    deck = Deck();
    deck.Shuffle();
    dealer_.DealCard(deck.RemoveCard());
    dealer_.DealCard(deck.RemoveCard());
    current_winner_ = "";
}

void GameEngine::Draw(Turn turn) {

    // Drawing each player and then dealer
    for (int i = 0; i < num_players_; i++) {
        players_[i].Draw(i, num_players_);
    }

    dealer_.DrawDealer((int) turn);

    // Drawing the center of game which states either whose turn it is, or the winner of the hand
    if (turn == Turn::GAME_FINISHED) {
        ci::gl::drawStringCentered(
                current_winner_,
                glm::vec2(kWindowSize / 2, kWindowSize / 2 - kMargin / 2),
                ci::Color("white"),
                cinder::Font("times", (float) kMargin / 6));
    } else {
        std::string turn_string = "It is ";
        for (Player &player : players_) {
            if (player.GetHasPlayed()) {
                continue;
            } else {
                turn_string += player.GetName();
                break;
            }
        }
        if (turn == Turn::DEALERS_TURN) {
            turn_string += "the Dealer";
        }
        turn_string += "'s turn.";

        ci::gl::drawStringCentered(
                turn_string,
                glm::vec2(kWindowSize / 2, kWindowSize / 2 - kMargin / 2),
                ci::Color("white"),
                cinder::Font("times", (float) kMargin / 6));
    }

    // Drawing a win scoreboard in the top right of screen
    ci::gl::drawStringCentered("Win Scoreboard",
                               glm::vec2(kWindowSize - kMargin, (kCardMargin / 3) * 2),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 5));

    std::string dealer_score = "Dealer: " + std::to_string(dealer_.GetWinCount());
    ci::gl::drawStringCentered(dealer_score,
                               glm::vec2(kWindowSize - kMargin, kMargin / 5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));

    for (int i = 0; i < num_players_; i++) {
        std::string score = "Player " + std::to_string(i + 1) + ": ";
        score += std::to_string(players_[i].GetWinCount());

        ci::gl::drawStringCentered(score,
                                   glm::vec2(kWindowSize - kMargin, (i + 2) * kMargin / 5 + kCardMargin),
                                   ci::Color("white"),
                                   cinder::Font("times", (float) kMargin / 6));
    }

    // Drawing list of instructors for input on top left of screen
    ci::gl::drawStringCentered("Game Instructions",
                               glm::vec2(kMargin, (kCardMargin / 3) * 2),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 5));
    ci::gl::drawStringCentered("Press H to hit",
                               glm::vec2(kMargin, kMargin / 5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
    ci::gl::drawStringCentered("Press S to stay",
                               glm::vec2(kMargin, 2 * kMargin / 5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
    ci::gl::drawStringCentered("Press N to play again",
                               glm::vec2(kMargin, 3 * kMargin / 5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
    ci::gl::drawStringCentered("Press Q to quit",
                               glm::vec2(kMargin, 4 * kMargin / 5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
}

void GameEngine::Update() {
    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            current_turn_ = Turn::NUM_PLAYERS;
            break;
        case Turn::NUM_PLAYERS:
            AddPlayers(num_players_);
            current_turn_ = Turn::PLAYERS_TURN;
            break;
        case Turn::PLAYERS_TURN: {
            // Checking to see if player bust and moving to next player's turn if so
            for (Player &player : players_) {
                if (player.GetHasPlayed()) {
                    continue;
                } else {
                    if (player.CalculateScore() > 21) {
                        player.SetHasPlayed(true);
                    }
                    break;
                }
            }

            // Seeing if all players have played and moving to dealer's turn if so
            bool all_played = true;
            for (Player &player : players_) {
                if (!player.GetHasPlayed()) {
                    all_played = false;
                }
            }
            if (all_played) {
                current_turn_ = Turn::DEALERS_TURN;
                Update();
            }
            break;
        }
        case Turn::DEALERS_TURN:
            // Hitting until dealer's score is at or above 17, then moving on to next state
            while (dealer_.CalculateScore() < 17) {
                dealer_.DealCard(deck.RemoveCard());
            }
            current_turn_ = Turn::GAME_FINISHED;
            Update();
            break;
        case Turn::GAME_FINISHED:
            current_winner_ = CalculateWinner();
            break;
    }
}

void GameEngine::AddPlayers(int num_players) {
    num_players_ = num_players;
    players_.clear();
    for (int i = 1; i <= num_players; i++) {
        Player player = Player("Player " + std::to_string(i));
        player.DealCard(deck.RemoveCard());
        player.DealCard(deck.RemoveCard());
        players_.push_back(player);
    }
}

void GameEngine::Reset() {
    num_players_ = 0;
    players_.clear();
    deck = Deck();
    deck.Shuffle();
    dealer_.ClearWins();
    dealer_.ClearHand();
    dealer_.DealCard(deck.RemoveCard());
    dealer_.DealCard(deck.RemoveCard());
    current_turn_ = Turn::HOME_SCREEN;
    current_winner_ = "";
}

void GameEngine::NewGame() {
    deck = Deck();
    deck.Shuffle();
    dealer_.ClearHand();
    dealer_.DealCard(deck.RemoveCard());
    dealer_.DealCard(deck.RemoveCard());
    for (Player &player : players_) {
        player.SetHasPlayed(false);
        player.ClearHand();
        player.DealCard(deck.RemoveCard());
        player.DealCard(deck.RemoveCard());
    }
    current_winner_ = "";
    current_turn_ = Turn::PLAYERS_TURN;
}

std::string GameEngine::CalculateWinner() {
    int winning_score = -1;

    // Setting highest score at or below 21
    for (const Player &player : players_) {
        if (player.CalculateScore() > winning_score && player.CalculateScore() <= 21) {
            winning_score = player.CalculateScore();
        }
    }

    if (dealer_.CalculateScore() > winning_score && dealer_.CalculateScore() <= 21) {
        winning_score = dealer_.CalculateScore();
    }

    std::vector<Player> winners;

    // Adding all players with winning score to winners
    for (Player &player : players_) {
        if (player.CalculateScore() == winning_score) {
            winners.push_back(player);
            player.AddWin();
        }
    }

    if (dealer_.CalculateScore() == winning_score) {
        winners.push_back(dealer_);
        dealer_.AddWin();
    }

    // Listing winner/winners and adding wins to player's counts, if no winners dealer automatically wins
    if (winners.size() == 1) {
        return winners[0].GetName() + " won!";
    } else if (winners.size() > 1) {
        std::string winners_names;
        winners_names += winners[0].GetName();
        for (int i = 1; i < winners.size(); i++) {
            winners_names += " and " + winners[i].GetName();
        }
        winners_names += " won!";
        return winners_names;
    } else {
        dealer_.AddWin();
        return dealer_.GetName() += " won!";
    }
}

Turn GameEngine::GetCurrentState() const {
    return current_turn_;
}

void GameEngine::SetPlayerNumber(int num_players) {
    num_players_ = num_players;
}

void GameEngine::Hit() {
    for (Player &player : players_) {
        if (player.GetHasPlayed()) {
            continue;
        } else {
            player.DealCard(deck.RemoveCard());
            break;
        }
    }
}

void GameEngine::Stay() {
    for (Player &player : players_) {
        if (player.GetHasPlayed()) {
            continue;
        } else {
            player.SetHasPlayed(true);
            break;
        }
    }
}

const std::vector<Player> & GameEngine::GetPlayers() const {
    return players_;
}

} // namespace blackjack
#include "game_engine.h"


namespace blackjack {

GameEngine::GameEngine() {
    dealer_ = Player("Dealer");
    current_turn_ = Turn::HOME_SCREEN;
    num_players_ = 0;
    deck = Deck();
    deck.Shuffle();
    dealer_.DealCard(deck.RemoveCard());
    dealer_.DealCard(deck.RemoveCard());
    current_winner_ = "";
}

void GameEngine::Update(ci::app::KeyEvent event) {
    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            if (event.getCode() == ci::app::KeyEvent::KEY_RETURN) {
                current_turn_ = Turn::NUM_PLAYERS;
            }
            break;
        case Turn::NUM_PLAYERS:
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_1:
                    AddPlayers(1);
                    current_turn_ = Turn::PLAYERS_TURN;
                    break;
                case ci::app::KeyEvent::KEY_2:
                    AddPlayers(2);
                    current_turn_ = Turn::PLAYERS_TURN;
                    break;
                case ci::app::KeyEvent::KEY_3:
                    AddPlayers(3);
                    current_turn_ = Turn::PLAYERS_TURN;
                    break;
                case ci::app::KeyEvent::KEY_4:
                    AddPlayers(4);
                    current_turn_ = Turn::PLAYERS_TURN;
                    break;
                case ci::app::KeyEvent::KEY_q:
                    current_turn_ = Turn::HOME_SCREEN;
            }
            break;
        case Turn::PLAYERS_TURN: {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_h:
                    for (Player &player : players_) {
                        if (player.GetHasPlayed()) {
                            continue;
                        } else {
                            player.DealCard(deck.RemoveCard());
                            break;
                        }
                    }
                    break;
                case ci::app::KeyEvent::KEY_s:
                    for (Player &player : players_) {
                        if (player.GetHasPlayed()) {
                            continue;
                        } else {
                            player.SetHasPlayed(true);
                            break;
                        }
                    }
                    break;
                case ci::app::KeyEvent::KEY_n:
                    NewGame();
                    break;
                case ci::app::KeyEvent::KEY_q:
                    Reset();
                    break;
            }

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

            bool all_played = true;
            for (Player& player : players_) {
                if (!player.GetHasPlayed()) {
                    all_played = false;
                }
            }
            if (all_played) {
                current_turn_ = Turn::DEALERS_TURN;
                Update(event);
            }
            break; }
        case Turn::DEALERS_TURN:
            while (dealer_.CalculateScore() < 17) {
                dealer_.DealCard(deck.RemoveCard());
            }
            current_turn_ = Turn::GAME_FINISHED;
            Update(event);
            break;
        case Turn::GAME_FINISHED:
            if (current_winner_.empty()) current_winner_ = CalculateWinner();

            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_q:
                    Reset();
                    break;
                case ci::app::KeyEvent::KEY_n:
                    NewGame();
                    break;
            }
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
    for (Player& player : players_) {
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

    for (const Player& player : players_) {
        if (player.CalculateScore() > winning_score && player.CalculateScore() <= 21) {
            winning_score = player.CalculateScore();
        }
    }

    if (dealer_.CalculateScore() > winning_score && dealer_.CalculateScore() <= 21) {
        winning_score = dealer_.CalculateScore();
    }

    std::vector<Player> winners;

    for (Player& player : players_) {
        if (player.CalculateScore() == winning_score) {
            winners.push_back(player);
            player.AddWin();
        }
    }

    if (dealer_.CalculateScore() == winning_score) {
        winners.push_back(dealer_);
        dealer_.AddWin();
    }

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

void GameEngine::Draw(Turn turn) {
    for (int i = 0; i < num_players_; i++) {

        int card_margin_factor = -1 * players_[i].GetHand().size() / 2;
        int card_shift = 0;

        if (players_[i].GetHand().size() % 2 == 0) {
            card_shift = (int)(kCardMargin / 2);
        }

        for (Card card : players_[i].GetHand()) {
            ci::gl::Texture2dRef tex = ci::gl::Texture2d::create(
                    loadImage(ci::app::loadAsset(card.GetImageURL())));

            double card_height = 1.0 * tex->getHeight() / 6;
            double card_width = 1.0 * tex->getWidth() / 6;

            ci::Rectf drawRect((kWindowSize * ((1.0 + i) / (1 + num_players_))) - (card_width / 2) + (card_margin_factor * kCardMargin) - card_shift + kCardMargin,
                               kWindowSize - (3 * kMargin),
                               (kWindowSize * ((1.0 + i) / (1 + num_players_))) - (card_width / 2) + (card_margin_factor * kCardMargin) - card_shift + card_width + kCardMargin,
                               kWindowSize - (3 * kMargin) + card_height);

            ci::gl::draw(tex, drawRect);

            card_margin_factor++;
        }

        std::string name = players_[i].GetName() + ": " + std::to_string(players_[i].CalculateScore());
        ci::gl::drawStringCentered(
                name,
                glm::vec2(kWindowSize * ((1.0 + i) / (1 + num_players_)), kWindowSize - kMargin / 2),
                ci::Color("white"),
                cinder::Font("times", (float) kMargin / 7));
    }


    int card_margin_factor = -1 * dealer_.GetHand().size() / 2;
    int card_shift = 0;
    int card_num = 0;

    if (dealer_.GetHand().size() % 2 == 0) {
        card_shift = kCardMargin / 2;
    }

    for (Card card : dealer_.GetHand()) {
        ci::gl::Texture2dRef tex;
        if (card_num != 0 && turn == Turn::PLAYERS_TURN) {
            tex = ci::gl::Texture2d::create(
                    loadImage(ci::app::loadAsset("gray_back.png")));
        } else {
            tex = ci::gl::Texture2d::create(
                    loadImage(ci::app::loadAsset(card.GetImageURL())));
        }

        double card_height = 1.0 * tex->getHeight() / 6;
        double card_width = 1.0 * tex->getWidth() / 6;

        ci::Rectf drawRect((kWindowSize / 2) - (card_width / 2) + (card_margin_factor * kCardMargin) - card_shift + kCardMargin,
                           (kMargin),
                           (kWindowSize / 2) - (card_width / 2) + (card_margin_factor * kCardMargin) - card_shift + card_width + kCardMargin,
                           (kMargin) + card_height);

        ci::gl::draw(tex, drawRect);

        card_margin_factor++;
        card_num++;
    }

    std::string name = dealer_.GetName();
    if (turn != Turn::PLAYERS_TURN) {
        name += ": " + std::to_string(dealer_.CalculateScore());
    }
    ci::gl::drawStringCentered(
            name,
            glm::vec2(kWindowSize / 2, kMargin / 2),
            ci::Color("white"),
            cinder::Font("times", (float) kMargin / 7));


    if (turn == Turn::GAME_FINISHED) {
        ci::gl::drawStringCentered(
                current_winner_,
                glm::vec2(kWindowSize /2, kWindowSize/2 - kMargin / 2),
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
                glm::vec2(kWindowSize /2, kWindowSize/2 - kMargin / 2),
                ci::Color("white"),
                cinder::Font("times", (float) kMargin / 6));
    }


    ci::gl::drawStringCentered("Win Scoreboard",
                               glm::vec2(kWindowSize - kMargin, (kCardMargin / 3) * 2),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 5));

    std::string dealer_score = "Dealer: " + std::to_string(dealer_.GetWinCount());
    ci::gl::drawStringCentered(dealer_score,
                               glm::vec2(kWindowSize - kMargin, kMargin/5 + kCardMargin),
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


    ci::gl::drawStringCentered("Game Instructions",
                               glm::vec2(kMargin, (kCardMargin/3) * 2),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 5));
    ci::gl::drawStringCentered("Press H to hit",
                               glm::vec2(kMargin, kMargin/5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
    ci::gl::drawStringCentered("Press S to stay",
                               glm::vec2(kMargin, 2 * kMargin/5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
    ci::gl::drawStringCentered("Press N to play again",
                               glm::vec2(kMargin, 3 * kMargin/5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
    ci::gl::drawStringCentered("Press Q to quit",
                               glm::vec2(kMargin, 4 * kMargin/5 + kCardMargin),
                               ci::Color("white"),
                               cinder::Font("times", (float) kMargin / 6));
}

} // namespace blackjack
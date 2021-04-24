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

    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void GameEngine::draw() {
    ci::Color8u background_color(30, 135, 70); // dark green
    ci::gl::clear(background_color);

    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            ci::gl::drawStringCentered(
                    "Welcome to Blackjack",
                    glm::vec2(kWindowSize / 2, kWindowSize / 2),
                    ci::Color("black"),
                    cinder::Font("times", (float) kWindowSize / 10));
            ci::gl::drawStringCentered(
                    "Press Enter to Play",
                    glm::vec2(kWindowSize / 2, (kWindowSize / 2) + kMargin),
                    ci::Color("black"), cinder::Font("times", (float) kMargin / 8));
            break;
        case Turn::NUM_PLAYERS:
            ci::gl::drawStringCentered(
                    "Please select the number of players (1 through 4)",
                    glm::vec2(kWindowSize / 2, (kWindowSize / 2)),
                    ci::Color("black"), cinder::Font("times", (float) kMargin / 5));
            break;
        case Turn::PLAYERS_TURN: {
            DrawGameBoard(false);
            break;
        }
        case Turn::DEALERS_TURN:
            DrawGameBoard(true);
            break;
        case Turn::GAME_FINISHED:
            break;
    }
}

void GameEngine::Update() {
    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            break;
        case Turn::NUM_PLAYERS:
            break;
        case Turn::PLAYERS_TURN: {
            for (Player &player : players_) {
                if (player.GetHasPlayed()) {
                    continue;
                } else {
                    if (player.GetScore() > 21) {
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
                Update();
            }
            break; }
        case Turn::DEALERS_TURN:
            while (dealer_.GetScore() < 17) {
                dealer_.DealCard(deck.RemoveCard());
            }
//            current_turn_ = Turn::GAME_FINISHED;
//            Update();
            break;
        case Turn::GAME_FINISHED:
            break;
    }
}

void GameEngine::keyDown(ci::app::KeyEvent event) {
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
        case Turn::PLAYERS_TURN:
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
                case ci::app::KeyEvent::KEY_q:
                    Reset();
            }
            Update();
            break;
        case Turn::DEALERS_TURN:
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_q:
                    Reset();
                    break;
            }
            break;
        case Turn::GAME_FINISHED:
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
    dealer_.ClearHand();
    dealer_.DealCard(deck.RemoveCard());
    dealer_.DealCard(deck.RemoveCard());
    current_turn_ = Turn::HOME_SCREEN;
}

void GameEngine::DrawGameBoard(bool is_dealers_turn) {
    for (int i = 0; i < num_players_; i++) {

        int card_margin_factor = -1 * players_[i].GetHand().size() / 2;
        int card_shift = 0;

        if (players_[i].GetHand().size() % 2 == 0) {
            card_shift = kCardMargin / 2;
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

        std::string name = players_[i].GetName() + ": " + std::to_string(players_[i].GetScore());
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
        if (card_num != 0 && !is_dealers_turn) {
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
    if (is_dealers_turn) {
        name += ": " + std::to_string(dealer_.GetScore());
    }
    ci::gl::drawStringCentered(
            name,
            glm::vec2(kWindowSize / 2, kMargin / 2),
            ci::Color("white"),
            cinder::Font("times", (float) kMargin / 7));


    std::string turn = "It is ";
    for (Player &player : players_) {
        if (player.GetHasPlayed()) {
            continue;
        } else {
            turn += player.GetName();
            break;
        }
    }
    if (is_dealers_turn) {
        turn += "the Dealer";
    }
    turn += "'s turn.";
    ci::gl::drawStringCentered(
            turn,
            glm::vec2(kWindowSize /2, kWindowSize/2 - kMargin / 2),
            ci::Color("white"),
            cinder::Font("times", (float) kMargin / 6));
}

} // namespace blackjack
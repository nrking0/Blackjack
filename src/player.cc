#include "player.h"

#include <utility>

namespace blackjack {

Player::Player(std::string name) {
    name_ = std::move(name);
    has_played_ = false;
    win_count = 0;
}

const std::vector<Card>& Player::GetHand() const {
    return hand_;
}

void Player::DealCard(Card card) {
    hand_.push_back(card);
}

void Player::ClearHand() {
    hand_.clear();
}

bool Player::GetHasPlayed() const {
    return has_played_;
}

std::string Player::GetName() const {
    return name_;
}

int Player::CalculateScore() const {
    int score = 0;
    bool has_ace = false;
    for (Card card : hand_) {
        if ((int) card.GetRank() > 10) {
            score += 10;
        } else {
            if ((int)card.GetRank() == 1) {
                has_ace = true;
            }
            score += (int) card.GetRank();
        }
    }

    if (score <= 11 && has_ace) {
        score += 10;
    }
    return score;
}

void Player::SetHasPlayed(bool has_played) {
    has_played_ = has_played;
}

void Player::AddWin() {
    win_count++;
}

int Player::GetWinCount() const {
    return win_count;
}

void Player::ClearWins() {
    win_count = 0;
}

void Player::Draw(int player_index, int num_players) const {
    int card_margin_factor = -1 * this->GetHand().size() / 2;
    int card_shift = 0;

    if (this->GetHand().size() % 2 == 0) {
        card_shift = (int)(kCardMargin / 2);
    }

    for (Card card : this->GetHand()) {
        ci::gl::Texture2dRef tex = ci::gl::Texture2d::create(
                loadImage(ci::app::loadAsset(card.GetImageURL())));

        double card_height = 1.0 * tex->getHeight() / 6;
        double card_width = 1.0 * tex->getWidth() / 6;

        ci::Rectf drawRect((kWindowSize * ((1.0 + player_index) / (1 + num_players))) - (card_width / 2) + (card_margin_factor * kCardMargin) - card_shift + kCardMargin,
                           kWindowSize - (3 * kMargin),
                           (kWindowSize * ((1.0 + player_index) / (1 + num_players))) - (card_width / 2) + (card_margin_factor * kCardMargin) - card_shift + card_width + kCardMargin,
                           kWindowSize - (3 * kMargin) + card_height);

        ci::gl::draw(tex, drawRect);

        card_margin_factor++;
    }

    std::string name = this->GetName() + ": " + std::to_string(this->CalculateScore());
    ci::gl::drawStringCentered(
            name,
            glm::vec2(kWindowSize * ((1.0 + player_index) / (1 + num_players)), kWindowSize - kMargin / 2),
            ci::Color("white"),
            cinder::Font("times", (float) kMargin / 7));
}

void Player::DrawDealer(int turn) const {
    int card_margin_factor = -1 * this->GetHand().size() / 2;
    int card_shift = 0;
    int card_num = 0;

    if (this->GetHand().size() % 2 == 0) {
        card_shift = kCardMargin / 2;
    }

    for (Card card : this->GetHand()) {
        ci::gl::Texture2dRef tex;
        if (card_num != 0 && turn == 2) {
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

    std::string name = this->GetName();
    if (turn != 2) {
        name += ": " + std::to_string(this->CalculateScore());
    }
    ci::gl::drawStringCentered(
            name,
            glm::vec2(kWindowSize / 2, kMargin / 2),
            ci::Color("white"),
            cinder::Font("times", (float) kMargin / 7));
}

} // namespace blackjack
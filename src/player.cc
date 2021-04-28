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

int Player::GetScore() const {
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

} // namespace blackjack
#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <string>
#include <vector>
#include "card.h"

namespace blackjack {

class Player {

public:
    Player(std::string name);
    const std::vector<Card>& GetHand() const;
    int GetScore() const;
    void DealCard(Card card);
    void ClearHand();
    std::string GetName() const;
    bool GetHasPlayed() const;
    void SetHasPlayed(bool has_played);


private:
    std::string name_;
    std::vector<Card> hand_;
    bool has_played_;

};

} // namespace blackjack

#endif //BLACKJACK_PLAYER_H

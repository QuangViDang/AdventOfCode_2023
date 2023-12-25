"""
https://adventofcode.com/2023/day/7

--- Part Two ---
To make things a little more interesting, the Elf introduces one additional rule. Now, J cards are jokers - wildcards that can act like whatever card would make the hand the strongest type possible.

To balance this, J cards are now the weakest individual cards, weaker even than 2. The other cards stay in the same order: A, K, Q, T, 9, 8, 7, 6, 5, 4, 3, 2, J.

J cards can pretend to be whatever card is best for the purpose of determining hand type; for example, QJJQ2 is now considered four of a kind. However, for the purpose of breaking ties between two hands of the same type, J is always treated as J, not the card it's pretending to be: JKKK2 is weaker than QQQQ2 because J is weaker than Q.

Now, the above example goes very differently:

32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483
32T3K is still the only one pair; it doesn't contain any jokers, so its strength doesn't increase.
KK677 is now the only two pair, making it the second-weakest hand.
T55J5, KTJJT, and QQQJA are now all four of a kind! T55J5 gets rank 3, QQQJA gets rank 4, and KTJJT gets rank 5.
With the new joker rule, the total winnings in this example are 5905.

Using the new joker rule, find the rank of every hand in your set. What are the new total winnings?
"""

from collections import Counter, defaultdict
from enum import IntEnum, auto
from operator import itemgetter

with open("input.txt") as f:
    lines = f.read().splitlines()


class HandType(IntEnum):
    FIVE_OF_A_KIND = auto()
    FOUR_OF_A_KIND = auto()
    FULL_HOUSE = auto()
    THREE_OF_A_KIND = auto()
    TWO_PAIRS = auto()
    ONE_PAIR = auto()
    HIGH_CARD = auto()


CARDS = ["A", "K", "Q", "T", "9", "8", "7", "6", "5", "4", "3", "2", "J"]


def calculate_strength(hand):
    cards = Counter(hand)
    if "J" in cards:
        j = cards.pop("J")
        if not cards:
            return HandType.FIVE_OF_A_KIND

        cards[max(cards, key=cards.get)] += j

    if len(cards) == 1:
        return HandType.FIVE_OF_A_KIND

    if len(cards) == 2:
        if 4 in cards.values():
            return HandType.FOUR_OF_A_KIND

        return HandType.FULL_HOUSE

    if len(cards) == 3:
        if 3 in cards.values():
            return HandType.THREE_OF_A_KIND

        return HandType.TWO_PAIRS

    if len(cards) == 4:
        return HandType.ONE_PAIR

    return HandType.HIGH_CARD


def compare_cards(cards):
    return [CARDS.index(card) for card in cards[0]]


strengths = defaultdict(list)

for line in lines:
    hand, bid = line.split()
    bid_number = int(bid)

    strengths[calculate_strength(hand)].append((hand, bid_number))

bids = []
for key in sorted(strengths):
    values = sorted(strengths[key], key=itemgetter(0))
    for value in sorted(values, key=compare_cards):
        bids.append(value[1])

print(sum(bid * i for i, bid in enumerate(reversed(bids), start=1)))
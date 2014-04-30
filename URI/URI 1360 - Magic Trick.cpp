#include <iostream>
#include <vector>

using namespace std;

enum Suit {
   HEART = 0,
   CLUB,
   DIAMOND, 
   SPADE
};

Suit parseSuit(char suit) {
   switch(suit) {
      case 'H':
         return HEART;
      case 'C':
         return CLUB;
      case 'D':
         return DIAMOND;
      default:
         return SPADE;
   }
}

int parseValue(char value) {
   switch(value) {
      case 'T':
         return 10;
      case 'J':
         return 11;
      case 'Q':
         return 12;
      case 'K':
         return 13;
   }

   return value - '0';
}

char getCharSuit(Suit suit) {
   switch(suit) {
      case HEART:
         return 'H';
      case CLUB:
         return 'C';
      case DIAMOND:
         return 'D';
   }

   return 'S';
}

char getCharValue(int value) {
   switch(value) {
      case 10: 
         return 'T';
      case 11:
         return 'J';
      case 12:
         return 'Q';
      case 13:
         return 'K';
   }

   return (char)(value + '0');
}

struct Card {
   int value;
   Suit suit;

   Card(int v, Suit s) : value(v), suit(s) { }

   bool operator<(const Card other) const {
      if (suit == other.suit) {
         return value < other.value;
      }

      return suit < other.suit;
   }
};

Card readCard() {
   char value, suit;
   cin >> value >> suit;

   return Card(parseValue(value), parseSuit(suit));
}

int decodeOrder(const vector<Card>& v) {
   if (v[1] < v[2] && v[2] < v[3])
      return 1;

   if (v[1] < v[3] && v[3] < v[2])
      return 2;

   if (v[2] < v[1] && v[1] < v[3])
      return 3;

   if (v[3] < v[1] && v[1] < v[2])
      return 4;

   if (v[2] < v[3] && v[3] < v[1])
      return 5;

   return 6;
}

int main() {
   int n;
   cin >> n;

   for(int i = 0; i < n; ++i) {
      vector<Card> v;

      for(int j = 0; j < 4; ++j)
         v.push_back(readCard());

      int value = ((v[0].value + decodeOrder(v) - 1) % 13) + 1;
      cout << getCharValue(value) << getCharSuit(v[0].suit) << '\n';

   }
}

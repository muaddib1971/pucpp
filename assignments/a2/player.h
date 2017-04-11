/// class player - 
class player {
  // Attributes
private:
  std::string username;
  std::string password;
  const int intelligence;
  const int wisdom;
  const int dexterity;
  const int strength;
  const int constitution;
  int hp;
  int mana;
  int moves;
  room *  location;
  item * equipment [NUM_WEAR_SLOTS];
  stl_container inventory;
  int gold_pieces;
  // Operations
public:
  void look ();
  void look (direction dir);
  void look (const item& item);
  void open (direction dir);
  void close (direction dir);
  purchase_result buy (int listnum);
  purchase_result buy (std::string name);
  int balance ();
  wear_result wear (const item& item);
  void list ();
  move (direction dir);
  quit ();
};


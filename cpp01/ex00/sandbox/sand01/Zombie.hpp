#include <string>

class Zombie {
  std::string name_;

 public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
};

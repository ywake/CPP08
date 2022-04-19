#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
  /*
   * member types and aliases
   */
  typedef typename std::stack<T>::container_type container_type;
  typedef typename container_type::iterator iterator;
  typedef typename container_type::const_iterator const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  /*
   * Constructor/Destructor
   */
  MutantStack() : std::stack<T>() {}
  MutantStack(MutantStack const &copy) { *this = copy; }
  ~MutantStack() {}

  /*
   * Operators
   */
  MutantStack &operator=(MutantStack const &other)
  {
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }

  /*
   * Getter/Setter
   */

  /*
   * Methods
   */
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  iterator rbegin() { return this->c.rbegin(); }
  iterator rend() { return this->c.rend(); }

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
  const_iterator rbegin() const { return this->c.rbegin(); }
  const_iterator rend() const { return this->c.rend(); }
};

#endif /* MUTANTSTACK_HPP */

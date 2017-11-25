#ifndef IteratorInterface_h
#define IteratorInterface_h
class IteratorInterface {
  public:
    bool hasNext();
    template<typename T> T * next();
    unsigned int getIndex();
  private:
    unsigned int m_index;
};
#endif

template<typename t>
class Node{
    public:
    t data;
    Node<t>*nxt;

    Node(t d){
        data = d;
    }
};

template<typename t>
class Stack{

  Node<t>*head;

  public:
  Stack()
  {
      head=NULL;
  }

  void push(t data)
  {
      Node<t> *n = new Node<t>(data);
      n->nxt = head;
      head = n;
  }

  bool empty(){
      return head==NULL;
  }

  t top()
  { 
      return head->data;
  }

  void pop()
  {
      if(head!=NULL){Node<t> *tmp = head;
      head = head->nxt;
      delete (tmp);}
  }  

};


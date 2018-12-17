#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

template<typename T>
class LinkedListElement{
    public:
        LinkedListElement(){
            static int globalKey = 0;
            nextElement = NULL;
            prevElement = NULL;
            key = globalKey++;
        }

        LinkedListElement(T value_a){
            static int globalKey = 0;
            nextElement = NULL;
            prevElement = NULL;
            key = globalKey++;
            value = value_a;
        }

        int getKey(){
            return key;
        }
        T getValue(){
            return value;
        }
        LinkedListElement<T>* getNextElement(){
            return nextElement;
        }
        LinkedListElement<T>* getPrevElement(){
            return prevElement;
        }

        void setKey(int key_a){
            key = key_a;
        }
        void setValue(T value_a){
            value = value_a;
        }
        void setNextElement(LinkedListElement<T>* nextElement_a){
            nextElement = nextElement_a;
        }
        void setPrevElement(LinkedListElement<T>* prevElement_a){
            prevElement = prevElement_a;
        }
    private:
        LinkedListElement<T>* nextElement;
        LinkedListElement<T>* prevElement;
        T value;
        int key;
};

template <typename T>
class LinkedList{
    public:
        LinkedList(){
            header = new LinkedListElement<T>();
        }

        void setHeader(LinkedListElement<T>* header_a){
            header = header_a;
        }

        LinkedListElement<T>* getHeader(){
            return header;
        }

        friend LinkedListElement<T>* findElement(LinkedList<T>& list, int key_a);
        friend void deleteElement(LinkedList<T>& list, int key_a);
        friend void updateElement(LinkedList<T>& list, int key_a, T value_a);
        friend void addElement(LinkedList<T>& list, T value_a);
        friend void showList(LinkedList<T>& list);
    private:
        LinkedListElement<T>* header;

};

template<typename T>
void showList(LinkedList<T>& list){
    LinkedListElement<T>* header = list.getHeader();
    if((*header).getNextElement()==NULL){
        cout<<"List is empty"<<endl;
    }else{
        LinkedListElement<T>* element = (*header).getNextElement();
        while(element!=header){
            cout<<"Element's key:"<<(*element).getKey()<<" and value:"<<(*element).getValue()<<endl;
            element = (*element).getNextElement();
        }
    }
}

template<typename T>
void addElement(LinkedList<T>& list, T value_a){
    LinkedListElement<T>* header = list.getHeader();
    LinkedListElement<T>* newElement = new LinkedListElement<T>(value_a);
    if((*header).getNextElement()==NULL){
        (*header).setNextElement(newElement);
        (*header).setPrevElement(newElement);
        (*newElement).setNextElement(header);
        (*newElement).setPrevElement(header);
    }else{
        (*(*header).getPrevElement()).setNextElement(newElement);
        (*newElement).setPrevElement((*header).getPrevElement());
        (*header).setPrevElement(newElement);
        (*newElement).setNextElement(header);
    }
}

template<typename T>
void updateElement(LinkedList<T>& list, int key_a, T value_a){
    LinkedListElement<T>* header = list.getHeader();
    if((*header).getNextElement()==NULL){
        cout<<"List is empty"<<endl;
    }else{
        LinkedListElement<T>* element = (*header).getNextElement();
        while(element!=header){
            if((*element).getKey()==key_a){
                (*element).setValue(value_a);
            }
            element = (*element).getNextElement();
        }
    }
}

template<typename T>
LinkedListElement<T>* findElement(LinkedList<T>& list, int key_a){
    LinkedListElement<T>* header = list.getHeader();
    if((*header).getNextElement()==NULL){
        cout<<"List is empty"<<endl;
    }else{
        LinkedListElement<T>* element = (*header).getNextElement();
        while(element!=header){
            if((*element).getKey()==key_a){
                return element;
            }
            element = (*element).getNextElement();
        }
    }
}

template<typename T>
void deleteElement(LinkedList<T>& list, int key_a){
    LinkedListElement<T>* header = list.getHeader();
    if((*header).getNextElement()==NULL){
        cout<<"List is empty"<<endl;
    }else{
        LinkedListElement<T>* element = (*header).getNextElement();
        LinkedListElement<T>* delEl = NULL;
        while(element!=header && element!=NULL){
            if((*element).getKey()==key_a){
                if((*element).getNextElement()==header && (*element).getPrevElement()==header){
                    (*header).setNextElement(NULL);
                    (*header).setPrevElement(NULL);
                    delete element;
                    element = NULL;
                }else if((*element).getNextElement()==header && (*element).getPrevElement()!=header){
                    (*header).setPrevElement((*element).getPrevElement());
                    (*(*element).getPrevElement()).setNextElement(header);
                    delete element;
                    element = NULL;
                }else if((*element).getNextElement()!=header && (*element).getPrevElement()==header){
                    (*header).setNextElement((*element).getNextElement());
                    (*(*element).getNextElement()).setPrevElement(header);
                    delete element;
                    element = NULL;
                }else{
                    (*(*element).getPrevElement()).setNextElement((*element).getNextElement());
                    (*(*element).getNextElement()).setPrevElement((*element).getPrevElement());
                    delete element;
                    element = NULL;
                }
            }else
                element = (*element).getNextElement();          
        }
    }
}

class customType1{
    public:
        customType1(){}
        customType1(int int1_a, char char1_a):int1(int1_a),char1(char1_a){}
        char getChar1(){return char1;}
        int getInt1(){return int1;}
        friend ostream& operator<<(ostream& cout, customType1& c1);
    private:
        int int1;
        char char1;
};

ostream& operator<<(ostream& cout, customType1& c1){
    cout<<"Element's int:"<<c1.getInt1()<<" and char:"<<c1.getChar1()<<endl;
    return cout;
}

int main(void){
    LinkedList<int>* list = new LinkedList<int>();
    addElement<int>((*list),5);
    addElement<int>((*list),3);
    addElement<int>((*list),7);
    showList<int>((*list));
    deleteElement<int>((*list), 0);
    LinkedListElement<int>* element = findElement<int>((*list),2);
    cout<<"Found element's key:"<<(*element).getKey()<<" and value:"<<(*element).getValue()<<endl;
    updateElement<int>((*list), 1, 9);
    showList<int>((*list));
    cout<<"\n\n\n";
    LinkedList<float>* listF = new LinkedList<float>();
    addElement<float>((*listF),5.3);
    addElement<float>((*listF),3.3);
    addElement<float>((*listF),7.3);
    showList<float>((*listF));
    deleteElement<float>((*listF),2);
    LinkedListElement<float>* elementF = findElement<float>((*listF),0);
    cout<<"Found element's key:"<<(*elementF).getKey()<<" and value:"<<(*elementF).getValue()<<endl;
    updateElement<float>((*listF), 1, 9.3);
    showList<float>((*listF));
    cout<<"\n\n\n";
    LinkedList<char>* listC = new LinkedList<char>();
    addElement<char>((*listC),'A');
    addElement<char>((*listC),'B');
    addElement<char>((*listC),'C');
    showList<char>((*listC));
    deleteElement<char>((*listC),1);
    LinkedListElement<char>* elementC = findElement<char>((*listC),2);
    cout<<"Found element's key:"<<(*elementC).getKey()<<" and value:"<<(*elementC).getValue()<<endl;
    updateElement<char>((*listC), 0, 'D');
    showList<char>((*listC));
    return 0;
}
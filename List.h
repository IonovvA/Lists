#pragma once                                

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Link {
	int val;
	Link* next;
	Link(int _v = 0, Link* _n = nullptr) : val(_v), next(_n) {};
};

class List {
	Link* start;
    Link* end;
public:
	List() {
		start = new Link();
		start->next = start;
        end = start;
	}

    List(const List& list)                             
    {
        this->start = new Link();
        this->start->next = start;
        end = start;
        Link* tmp = list.start->next;
        while (tmp != list.start)
        {
            add_end(tmp->val);
            tmp = tmp->next;
        }
    }

    List& operator=(const List& list)
    {
        this->clear();
        Link* tmp = list.start->next;
        while (tmp != list.start)
        {
            add_end(tmp->val);
            tmp = tmp->next;
        }
        return *this;
    }
	
    void del_first() {
        Link* tmp = start->next;
        start->next = tmp->next;
        delete tmp;
    }

	void clear() {
        while (start->next != start)
            this->del_first();
        end = start;
	}

	bool exist(int a) {                                             
		Link* b = start->next;
		while (b != start) {
			if (b->val == a)
				return true;
			b = b->next;
		}
		return false;
	}

    void add(int a) {
        if (this->exist(a))
            return;
        else {
            Link* tmp1 = start->next;
            Link* tmp2 = new Link(a);
            if (tmp1->val > a)
            {
                tmp2->next = tmp1;
                start->next = tmp2;
                return;
            }
            while (tmp1->next != start) {
                if (tmp1->next->val > a) {
                    tmp2->next = tmp1->next;
                    tmp1->next = tmp2;
                    return;
                }
                tmp1 = tmp1->next;
            }
            tmp1->next = tmp2;
            tmp2->next = start;
            end = tmp2;
        }
    }

    void add_first(int a) {
        Link* tmp1 = start->next;
        Link* tmp2 = new Link(a);
        tmp2->next = tmp1;
        start->next = tmp2;
    }

    void add_end(int a) {
        Link* tmp = new Link(a, start);
        end->next = tmp;
        end = tmp;
    }
 

    friend ostream& operator<<(ostream& out, List& list)
    {
        Link* tmp = list.start->next;
        while (tmp != list.start) {
            out << tmp->val << ' ';
            tmp = tmp->next;
        }
        return out;
    }

    friend istream& operator>>(istream& in, List& list)
    {
        list.clear();
        string tmp;
        string sep = "$";
        in >> tmp;
        while (tmp != sep) {
            list.add_end(stoi(tmp));
            in >> tmp;
        }
        return in;
    }

    List Intersection(List& list1) {                                   
        List list;
        Link* tmp1 = this->start->next;
        Link* tmp2 = list1.start->next;
        while ((tmp2 != list1.start) && (tmp1 != this->start))
        {
            if (tmp1->val == tmp2->val)
            {
                list.add_end(tmp1->val);
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            else
            {
                if (tmp1->val > tmp2->val)
                    tmp2 = tmp2->next;
                else
                    tmp1 = tmp1->next;

            }
        }
        return list;
    }

    ~List()
    {
        Link* tmp = start->next;
        Link* tmp1 = tmp->next;
        while (tmp != start)
        {
            delete tmp;
            tmp = tmp1;
            tmp1 = tmp->next;
        }
    }

};





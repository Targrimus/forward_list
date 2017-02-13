#ifndef FORWARD_LIST_H_
#define FORWARD_LIST_H_


//	NODE implementation
template <typename T>
class forward_list_node{
public:
	using value_type = T;
	using pointer_type = T*;
	using reference_type = T&;

	forward_list_node(value_type value = 0) :  data(value), next(nullptr) {
	}

	forward_list_node<value_type> * get_next() const{
		return this->next;
	}

	void set_next(forward_list_node<value_type> * node){
		this->next = node;
	}

	value_type get_data() const{
		return this->data;
	}

	void set_data(value_type value){
		this->data = value;
	}

private:
	value_type data;
	forward_list_node<value_type> * next;
};


//	FORWARD_list implementation
template <typename T>
class forward_list{
public:
	using value_type = T;
	using pointer_type = T*;
	using reference_type = T&;

	using node = forward_list_node<value_type>;
	using node_pointer = node *;

	// ctor
	forward_list() : head(nullptr), tail(nullptr){
	}

	//	dtor
	~forward_list(){
		node_pointer ptr = this->head, tmptr;

		while(ptr != nullptr){
			tmptr = ptr;
			std::cout << "GC: " << ptr->get_data() << " deleting..." << std::endl;
			ptr = ptr->get_next();
			delete tmptr;
		}

	}

	forward_list& push_back(value_type value){
		node_pointer item = new node(value);

		if(this->tail) this->tail->set_next(item);
		this->tail = item;
		if(!this->head) this->head = this->tail;

		return *this;
	}

	value_type pop_front(){
		node_pointer item;
		value_type data = 0;

		if(this->tail && this->head){
			data = this->head->get_data();
			item = this->head;
			this->head = this->head->get_next();
		}

		return data;
	}


private:
	node_pointer head, tail;
};



#endif /* FORWARD_LIST_H_ */

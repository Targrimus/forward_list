#ifndef FORWARD_LIST_H_
#define FORWARD_LIST_H_
#include <iostream>

/*******************************
 * forward_list implementation
 *******************************/

template <typename T>
class forward_list{

	//	forward declaration of node class
	class forward_list_node;

public:
	using node = forward_list_node;
	using node_pointer = node*;
	using value_type = T;
	using pointer	= T*;
	using reference	= T&;
	using const_reference = const T&;
	using counter_t	= std::size_t;

	//	default ctor
	forward_list();

	//	copy ctor
	//forward_list(const forward_list &);

	// move ctor
	//forward_list(forward_list &&);

	//	dtor
	~forward_list();

	//	copy assignment
	//forward_list& operator=(const forward_list&);

	//	move assignment
	//forward_list& operator=(forward_list&&);


	//	empty()
	bool empty() const;

	// front() function
	value_type front() const;

	// back() function
	value_type back() const;

	//	push function
	forward_list& push_back(value_type);

	// pop_front() function
	void pop_front();



private:
	node_pointer _head, _tail;
	counter_t _counter;
};

//	empty()
template <typename T>
bool forward_list<T>::empty() const{
	return (this->_counter == 0);
}

//	default ctor
template <typename T>
forward_list<T>::forward_list() : _head(nullptr), _tail(nullptr), _counter(0){

}

template <typename T>
forward_list<T>::~forward_list(){
	node_pointer old_head;
	while(this->_head != nullptr){
		old_head = this->_head;
		std::cout << "[GC] deleting: " << old_head->getData() << std::endl;
		this->_head = this->_head->getNext();
		delete old_head;
		old_head = nullptr;
	}
}


// front() function
template <typename T>
typename forward_list<T>::value_type forward_list<T>::front() const{
	if(this->_head != nullptr)
		return this->_head->getData();

	return value_type();
}

// back() function
template <typename T>
typename forward_list<T>::value_type forward_list<T>::back() const{
	if(this->_tail != nullptr)
		return this->_tail->getData();

	return value_type();
}

//	push function
template <typename T>
forward_list<T>& forward_list<T>::push_back(typename forward_list<T>::value_type value){
	node_pointer item = new node(value);

	if(this->_tail) this->_tail->setNext(item);
	this->_tail = item;
	++this->_counter;
	if(!this->_head) this->_head = this->_tail;

	return *this;
}

// pop_front() function
template <typename T>
void forward_list<T>::pop_front(){
	if(this->_head && this->_tail){

		node_pointer item;
		value_type value;

		value = this->_head->getData();
		item = this->_head;
		this->_head = this->_head->getNext();
		delete item;
		--this->_counter;
	}
}



/******************************
 *	NODE CLASS implementation
 ******************************/

template <typename T>
class forward_list<T>::forward_list_node{
public:
	//	default ctor
	forward_list_node();

	//	value ctor
	forward_list_node(value_type);

	// setNext;
	void setNext(node_pointer);

	//	getNext;
	node_pointer getNext() const;

	// setData();
	void setData(value_type);

	//	getData();
	value_type getData() const;

private:
	node_pointer _next;
	value_type _data;
};


//	node default ctor;
template <typename T>
forward_list<T>::forward_list_node::forward_list_node() : _next(nullptr){
}

//	node value ctor
template <typename T>
forward_list<T>::forward_list_node::forward_list_node(value_type value) : _next(nullptr), _data(value) {
}

//	node setNext()
template <typename T>
void forward_list<T>::forward_list_node::setNext(node_pointer next){
	this->_next = next;
}

//	node getNext()
template <typename T>
typename forward_list<T>::node_pointer forward_list<T>::forward_list_node::getNext() const{
	return this->_next;
}

//	node setData()
template <typename T>
void forward_list<T>::forward_list_node::setData(value_type value){
	this->_data = value;
}

//	node getData()
template <typename T>
typename forward_list<T>::value_type forward_list<T>::forward_list_node::getData() const{
	return this->_data;
}




#endif /* FORWARD_LIST_H_ */

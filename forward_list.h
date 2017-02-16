#ifndef FORWARD_LIST_H_
#define FORWARD_LIST_H_

template <typename T>
class forward_list{
public:
	// forward declaration of node
	class forward_list_node;

	//	typedefs
	using node = forward_list_node;
	using node_pointer = node*;

	using value_type = T;
	using reference = value_type&;
	using const_reference = const reference;
	using size_type = std::size_t;

	forward_list();
	forward_list(const forward_list<value_type> &);
	forward_list(forward_list<value_type>&&);
	~forward_list();


	forward_list<value_type> & operator=(const forward_list<value_type> &);
	forward_list<value_type> & operator=(forward_list<value_type> &&);


	void push_front(const_reference);
	void push_front(value_type&&);

	void pop_front();

	bool empty() const;

	void swap(forward_list<value_type>&);

	reference front();
	const_reference front() const;

private:

	node_pointer _head, _tail;
	size_type _count;
	size_type _max_size;
};

/*
 *	NODE Class implementation
 */

template <typename T>
class forward_list<T>::forward_list_node{
public:
	forward_list_node();
	forward_list_node(const value_type&);
	forward_list_node(value_type &&);

	void setNext(node_pointer);
	node_pointer getNext() const;

	void setData(const value_type&);
	void setData(value_type&&);
	const value_type & getData() const;
private:
	value_type _data;
	node_pointer _next;
};



#endif /* FORWARD_LIST_H_ */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: David
 *
 * Modified on February 01, 2021
 */

#ifndef NODE_H
#define NODE_H


/*-----
  class: Node

  purpose: could be used to implement a node within a
           singly-linked list; each node instance has
           two data fields, one holding data and one holding
           the address of the next node instance in a list

           valueType should be set to be the desired type
           for the data to be stored within each node instance's
           data field

  constructors: has 4 constructors:
           *   a no-argument constructor, which sets the
	       new Node instance's data field to the default for
	       its valueType, and sets its link field to NULL
           *   two one-argument contructors -- 
               *   one expects a valueType value, and sets the new Node
                   instance's data field to that given value, and sets
                   its link field to NULL,

	       *   and the other expects a *Node value, and sets the new
                   Node instance's data field to the default for its
                   valueType, and sets its link field to the given
                   *Node address

           *   a two-argument constructor, which expects a
               valueType value and a *Node value, and sets

  getters: getData - returns the value in the node' data field

           getLink - returns the address of the next node in
                     a list of these nodes
      
  setters: setData - expects a value of type valueType,
                     returns nothing, and has the side-effect of
                     setting the node's data field to the given
		     value

           setLink - expects a value of type *Node,
                     returns nothing, and has the side-effect of
                     setting the node's link field to the given
                     address-of-a-Node

  written by: Sharon Tuttle
  modified by: David C. Tuttle
  last modified: 01 Feb 2021
 -----*/

typedef double valueType;

class Node {
    public:
        // what type of data is stored in this node? 


        // constructors

        Node();
        Node(Node *initLink);
        Node(const valueType& initData);
        Node(const valueType& initData, 
             Node *initLink);
 
        // getters - methods to GRAB data fields

        valueType   getData() const;
        Node* getLink() const;
        Node*       getLink();

        // setters - methods to SET data fields

        void setData(const valueType& newData);
        void setLink(Node* newLink);

    private:
        valueType dataField;
        Node      *linkField;
};


#endif /* NODE_H */


/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 4
Description: Using pointers
Input: Shopping cart class and items array
Output: Printing shopping cart and final cost
*/

#include "shopping_cart.h"
#include "item.h"
void ShoppingCart::addItem(Item* item)
{

	if(itemCount==itemsArrSize){
		resizeArray();
	}		
	items[itemCount]=item;
	itemCount++;



	//This should add the item parameter to the end of the items array.
	//If the items array does not have space to add the item, the array should be made bigger using the resize func
	//tion before adding the item
	//Add the item to the end of the array and increment the itemCount to count the newly added item

	//TODO: Finish the function
}

/* */
void ShoppingCart::resizeArray()
{
		Item** newarr=new Item*[itemsArrSize+RESIZE_AMOUNT];
		for(int i=0;i<itemCount;i++){
			newarr[i]=items[i];

		}
		itemsArrSize+=RESIZE_AMOUNT;
		delete[] items;
		items=newarr;
		
	

	//This should make the items array bigger by the const RESIZE_AMOUNT.
	//For example, if the array had 7 elements and RESIZE_AMOUNT is 4, the array afterwards should have 11 elements
	
	//Make a new, bigger array
	//Then, copy over the elements from the old array (do not delete the old items!!!)
	//Deallocate the old array (Remember how to specifically deallocate an array!)
	//And then finally update the size to reflect the size of the newly 
	//allocated items array. Make sure to update any pointers as needed.

	//The items variable should ALWAYS point to the array being used to hold shopping cart items,
	//the itemsCount should tell how many items are in that array, 
	//and the itemsArrSize tells the actual number of spaces in the array (occupied or not)

	//TODO: Finish the function
}

void ShoppingCart:: printCart(){

	for(int i=0;i<itemCount;i++){
		items[i]->printItemInfo();
	}

}

float ShoppingCart:: getTotalCost(){

	float Cost=0;
	for(int i = 0; i<itemCount;i++){
		Cost+=items[i]->getPrice()*items[i]->getQuantity();
		
	}
	return Cost;

}
//TODO: Write the printCart function definition to print all of the Items in the ShoppingCart

//TODO: Write the getTotalCost function to find the total cost of all the Items in the ShoppingCart

/* */
ShoppingCart::~ShoppingCart()
{
	for(int i=0;i<itemCount;i++){
		delete items[i];
	}
	delete [] items;

	//Clear out the shopping cart by first deleting all of the items contained within it
	//Then, deallocate the array that held all of those items
	//Remember that there are different deletes for different contexts, make sure you
	//are using he correct version.

	//TODO: Finish the function
}

// -------------------------- Constructors --------------------------

//Default constructor
ShoppingCart::ShoppingCart()
{
	//This should initialize the shopping cart to be empty by making the items array point to null
	//The count and size should be 0
	items = nullptr;
	itemCount = 0;
	itemsArrSize = 0;
}

//Constructor that initializes the array to a given size
ShoppingCart::ShoppingCart(int initial_size)
{
	//This constructor should construct an empty shopping cart, but allocate an array of the given size
	//Initialize the items array using the size, set the size variable, and initialize count to 0

	items = new Item*[initial_size];
	itemCount = 0;
	itemsArrSize = initial_size;
}
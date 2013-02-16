/*
In this prototype, find the most efficient way to fill a box with cheeses, and a room with boxes.

processor = 1 tall, 2 wide, 4 deep
box = 10 tall, 10 wide, 10 deep
room = 20 tall, 20 wide, 20 deep
*/

#include <iostream>

using namespace std;

int compare;
int thisBoxDimension, thisCheeseDimension;
int otherB_D, otherC_D;
int spaceUsed;
int bW, bD; //necessary for setInitialValues()

struct dimensions {
	int height, width, length;
};

void setInitialValues() {
	thisBoxDimension = bW;
    	otherB_D = bD;
    	spaceUsed = 0;
    	compare = 0;
};

void calculateInitialSpace_Cheeses() {
    for (spaceUsed = 0; (((spaceUsed + thisCheeseDimension) <= thisBoxDimension) && (otherC_D <= otherB_D)); compare++) { 
        spaceUsed += thisCheeseDimension;    
    }
};

void calculateRemainingSpace_Cheeses(int CHEESEDIM, int BOXDIM) {
	if (BOXDIM >= CHEESEDIM) { 
    		int multiple = (BOXDIM / CHEESEDIM); //figure out how many cheese.lengths fit in remaining box length
    		compare = (compare + (compare * multiple)); //multiply the deduced row by the multiple
    	}
};

	


/*start***********************************************************************************************************************************/
int main() {

//start by figuring out cheddar
	dimensions cheese;
		cheese.height = 3;
		cheese.width = 2;
		cheese.length = 3;

	dimensions box;
		box.height = 29;
		box.width = 22;
		box.length = 37;
		bW = box.width;
		bD = box.length;

	int noCheeses = 0;
    
    

//FIRST BOX////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*lay the cheeses widthwise to box.width****************************************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.length;

    	//add cheeses widthwise til box width is full, check that other cheesemeasure fits in box
	calculateInitialSpace_Cheeses();
   	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));  
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	noCheeses = compare;
    
/*lay the cheeses lengthwise to box.width***************************************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
   	calculateInitialSpace_Cheeses();	
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}

/*lay the cheeses heightwise to box.width && cheese.length to box.length********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.height;
    	otherC_D = cheese.length;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.width, (box.height - cheese.width));
    	if (cheese.width > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}

/*lay the cheeses heightwise to box.width && cheese.width to box.length*********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.height;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.width, (box.height - cheese.width));
    	if (cheese.width > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	}   

/*lay the cheeses widthwise to box.width && cheese.height to box.length********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.height;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.length, (box.height - cheese.length));
    	if (cheese.length > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	}   

/*lay the cheeses heightwise to box.width && cheese.width to box.length*********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.height;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.length, (box.height - cheese.length));
    	if (cheese.length > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	} 
    	
/*end cheese-to-box calculation************************************************************************************************************/
    	int cheddar = noCheeses;
    	cout << endl << endl << "The number of cheddar in a box = " << cheddar;











/***************************************************************************************************************************************/    	
//begin box to room calculation////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//this is now box dimensions
		cheese.height = 29;
		cheese.width = 22;
		cheese.length = 37;
	//this is now room dimensions
		box.height = 101;
		box.width = 179;
		box.length = 131;
		
/*lay the boxes widthwise to room.width****************************************************************************************************/
    	noCheeses = 0;
    	setInitialValues();
    	thisBoxDimension = box.width;
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.length;
    	

    	//add cheeses widthwise til box width is full, check that other cheesemeasure fits in box
	calculateInitialSpace_Cheeses();
   	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D)); 
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	noCheeses = compare;
    
/*lay the boxes lengthwise to room.width***************************************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
   	calculateInitialSpace_Cheeses();	
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}
	
	int room1 = noCheeses;
	cout << endl << "The number of cheddar boxes in room 1 = " << room1 << endl <<
		"The number of cheddars in room 1 = " << (cheddar * room1) << endl;

		












///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









//next, figure out colby
		cheese.height = 4;
		cheese.width = 4;
		cheese.length = 3;
		
		box.height = 29;
		box.width = 22;
		box.length = 37;

/*lay the cheeses widthwise to box.width****************************************************************************************************/
    	noCheeses = 0;
    	setInitialValues();
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.length;

    	//add cheeses widthwise til box width is full, check that other cheesemeasure fits in box
	calculateInitialSpace_Cheeses();
   	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));  
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	noCheeses = compare;
    
/*lay the cheeses lengthwise to box.width***************************************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
   	calculateInitialSpace_Cheeses();	
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}

/*lay the cheeses heightwise to box.width && cheese.length to box.length********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.height;
    	otherC_D = cheese.length;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.width, (box.height - cheese.width));
    	if (cheese.width > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}

/*lay the cheeses heightwise to box.width && cheese.width to box.length********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.height;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.width, (box.height - cheese.width));
    	if (cheese.width > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	}   

/*lay the cheeses widthwise to box.width && cheese.height to box.length*********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.height;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.length, (box.height - cheese.length));
    	if (cheese.length > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	}   

/*lay the cheeses heightwise to box.width && cheese.width to box.length************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.height;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.length, (box.height - cheese.length));
    	if (cheese.length > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	} 
    	
/*end cheese-to-box calculation************************************************************************************************************/
    	int colby = (noCheeses * 2);
    	cout << endl << endl << "The number of colby in a box = " << colby;











/***************************************************************************************************************************************/    	
//begin box to room calculation////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//this is now box dimensions
		cheese.height = 29;
		cheese.width = 22;
		cheese.length = 37;
	//this is now room dimensions
		box.height = 96;
		box.width = 103;
		box.length = 181;
		
/*lay the boxes widthwise to room.width****************************************************************************************************/
    	noCheeses = 0;
    	setInitialValues();
    	thisBoxDimension = box.width;
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.length;
    	

    	//add cheeses widthwise til box width is full, check that other cheesemeasure fits in box
	calculateInitialSpace_Cheeses();
   	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D)); 
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	noCheeses = compare;
    
/*lay the boxes lengthwise to room.width***************************************************************************************************/
    	setInitialValues();
    	thisBoxDimension = box.width;
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
   	calculateInitialSpace_Cheeses();	
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));  
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}
	
	int room2 = noCheeses;
	cout << endl << "The number of colby boxes in room 2 = " << room2 << endl <<
		"The number of colbies in room 2 = " << (colby * room2) << endl;
		
    	












///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









//next, figure out swiss
		cheese.height = 4;
		cheese.width = 12;
		cheese.length = 12;
		
		box.height = 29;
		box.width = 22;
		box.length = 37;

/*lay the cheeses widthwise to box.width****************************************************************************************************/
    	noCheeses = 0;
    	setInitialValues();
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.length;

    	//add cheeses widthwise til box width is full, check that other cheesemeasure fits in box
	calculateInitialSpace_Cheeses();
   	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));  
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	noCheeses = compare;
    
/*lay the cheeses lengthwise to box.width***************************************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
   	calculateInitialSpace_Cheeses();	
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}

/*lay the cheeses heightwise to box.width && cheese.length to box.length********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.height;
    	otherC_D = cheese.length;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.width, (box.height - cheese.width));
    	if (cheese.width > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}

/*lay the cheeses heightwise to box.width && cheese.width to box.length********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.height;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.width, (box.height - cheese.width));
    	if (cheese.width > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	}   

/*lay the cheeses widthwise to box.width && cheese.height to box.length*********************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.height;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.length, (box.height - cheese.length));
    	if (cheese.length > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	}   

/*lay the cheeses heightwise to box.width && cheese.width to box.length************************************************************************/
    	setInitialValues();
    	thisCheeseDimension = cheese.height;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
    	calculateInitialSpace_Cheeses();
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.length, (box.height - cheese.length));
    	if (cheese.length > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
       		noCheeses = compare;
    	} 
    	
/*end cheese-to-box calculation************************************************************************************************************/
    	int swiss = noCheeses;
    	cout << endl << endl << "The number of swiss in a box = " << swiss;











/***************************************************************************************************************************************/    	
//begin box to room calculation////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//this is now box dimensions
		cheese.height = 29;
		cheese.width = 22;
		cheese.length = 37;
	//this is now room dimensions
		box.height = 112;
		box.width = 93;
		box.length = 197;
		
/*lay the boxes widthwise to room.width****************************************************************************************************/
    	noCheeses = 0;
    	setInitialValues();
    	thisBoxDimension = box.width;
    	thisCheeseDimension = cheese.width;
    	otherC_D = cheese.length;
    	

    	//add cheeses widthwise til box width is full, check that other cheesemeasure fits in box
	calculateInitialSpace_Cheeses();
   	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D)); 
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	noCheeses = compare;
    
/*lay the boxes lengthwise to room.width***************************************************************************************************/
    	setInitialValues();
    	thisBoxDimension = box.width;
    	thisCheeseDimension = cheese.length;
    	otherC_D = cheese.width;

    	//add cheeses lengthwise til box width is full, check that other cheesemeasure fits in box
   	calculateInitialSpace_Cheeses();	
    	calculateRemainingSpace_Cheeses(otherC_D, (box.length - otherC_D));   
    	calculateRemainingSpace_Cheeses(cheese.height, (box.height - cheese.height));
    	if (cheese.height > box.height) {
    		compare = 0;
    	}

    	if (compare > noCheeses) {
        	noCheeses = compare;
    	}
	int room3 = noCheeses;
	cout << endl << "The number of swiss boxes in room 3 = " << room3 << endl <<
		"The number of swisses in room 3 = " << (swiss * room3) << endl << endl;




}//end

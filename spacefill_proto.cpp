/*
In this prototype, find the most efficient way to fill a box with processors, and a room with boxes.

processor = 1 tall, 2 wide, 4 deep
box = 10 tall, 10 wide, 10 deep
room = 20 tall, 20 wide, 20 deep
*/

#include <iostream>

using namespace std;

int compare;
int thisBoxDimension, thisChipDimension;
int otherB_D, otherC_D;
int spaceUsed;
int bW, bD; //necessary for setInitialValues()

struct dimensions {
	int height, width, depth;
};

void setInitialValues() {
	thisBoxDimension = bW;
    	otherB_D = bD;
    	spaceUsed = 0;
    	compare = 0;
};

void calculateInitialSpace_Chips() {
    for (spaceUsed = 0; (((spaceUsed + thisChipDimension) <= thisBoxDimension) && (otherC_D <= otherB_D)); compare++) { 
        spaceUsed += thisChipDimension;    
    }
};

void calculateRemainingSpace_Chips(int CHIPDIM, int BOXDIM) {
	if (BOXDIM >= CHIPDIM) { 
    		int multiple = (BOXDIM / CHIPDIM); //figure out how many chip.depths fit in remaining box depth
    		compare = (compare + (compare * multiple)); //multiply the deduced row by the multiple
    	}

    	else {
    		cout << "\n\nTHIS RUN INEFFICIENT"; //assuming more chips will always fit in a box's dimensions after initial row
    	}
};

	


/*start***********************************************************************************************************************************/
int main() {


	dimensions chip;
		chip.height = 1;
		chip.width = 10;
		chip.depth = 20;

	dimensions box;
		box.height = 20;
		box.width = 10;
		box.depth = 1;
		bW = box.width;
		bD = box.depth;

	dimensions room;
		room.height = 1;
		room.width = 4;
		room.depth = 8;

	int noChips = 0;
    
    

/*lay the chips widthwise to box.width****************************************************************************************************/
    	setInitialValues();
    	thisChipDimension = chip.width;
    	otherC_D = chip.depth;

    	//add chips widthwise til box width is full, check that other chipmeasure fits in box
	calculateInitialSpace_Chips();
   	calculateRemainingSpace_Chips(otherC_D, (box.depth - otherC_D));  
    	calculateRemainingSpace_Chips(chip.height, (box.height - chip.height));

    	noChips = compare;
    
/*lay the chips depthwise to box.width****************************************************************************************************/
    	setInitialValues();
    	thisChipDimension = chip.depth;
    	otherC_D = chip.width;

    	//add chips depthwise til box width is full, check that other chipmeasure fits in box
   	calculateInitialSpace_Chips();	
    	calculateRemainingSpace_Chips(otherC_D, (box.depth - otherC_D));   
    	calculateRemainingSpace_Chips(chip.height, (box.height - chip.height));

    	if (compare > noChips) {
        	noChips = compare;
    	}

/*lay the chips heightwise to box.width && chip.depth to box.depth************************************************************************/
    	setInitialValues();
    	thisChipDimension = chip.height;
    	otherC_D = chip.depth;

    	//add chips depthwise til box width is full, check that other chipmeasure fits in box
    	calculateInitialSpace_Chips();
    	calculateRemainingSpace_Chips(otherC_D, (box.depth - otherC_D));   
    	calculateRemainingSpace_Chips(chip.width, (box.height - chip.width));

    	if (compare > noChips) {
        	noChips = compare;
    	}

/*lay the chips heightwise to box.width && chip.width to box.depth************************************************************************/
    	setInitialValues();
    	thisChipDimension = chip.depth;
    	otherC_D = chip.height;

    	//add chips depthwise til box width is full, check that other chipmeasure fits in box
    	calculateInitialSpace_Chips();
    	calculateRemainingSpace_Chips(otherC_D, (box.depth - otherC_D));   
    	calculateRemainingSpace_Chips(chip.width, (box.height - chip.width));

    	if (compare > noChips) {
       		noChips = compare;
    	}   

/*end chip-to-box calculation************************************************************************************************************/
    	cout << endl << endl << "The number of chips in a box = " << noChips << endl << endl;//couting 16

}//end

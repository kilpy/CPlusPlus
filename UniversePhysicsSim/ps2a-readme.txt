/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Brent Garey
Hours to complete assignment: 14 hours 

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I implemented a celestialbody class, that when working, was able to function in main. I mainly had problems porting the functionality from main into a universe class. The universe class holds a vector of celestialbody pointers, where each celestialbody is an object that holds values for x and y positions, velocities, and textures for sprites. 
  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Classes, vectors. 




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The universe class will scan and store the first two numbers as number of planets
and radius of the universe respectively. It will then scan the document for the values to
initialize celestialbodies with. After each celestialbody is initialized, it is appended
onto a vector of celestialbody pointers which is held in the universe class



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
N/A

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
porting from main to universe class took a while to figure out.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Brent Garey

Hours to complete assignment : 8

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I am able to run the executable file and get the SFML window to pop up
and pressing keys plays a sound!

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 **********************************************************************/
Yes, I was able to recreate a drum / snare sound by changing decay rate to
1.00 and changing the tic function to sometimes invert the random value
being enqueued. I created a separate folder with a separate makefile 
that will create a KSDrum executable. 
/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, I made if statements to make sure arguements such as frequency were 
within bounds. I would then throw an exception that would let the user know
that frequency was less than 0. 
/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
NA


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I accidentally set decay factor as 0.096 rather than 0.996 So I wasnt receiving
a guitar sound but rather quick taps. 
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

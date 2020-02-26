#include <iostream>
using namespace std;

void vehicle (bool LeftDashboard, bool RightDashboard, bool ChildLock, bool MasterLock, 
bool InsideLeftLatch, bool OutsideLeftLatch, bool InsideRightLatch, bool OutsideRightLatch, bool Gearshift)
{	
	if	(!LeftDashboard && !RightDashboard)
	{
		if (!ChildLock)
		{
			if (!MasterLock)
			{
				if (InsideLeftLatch || InsideRightLatch) 
				{
					if (OutsideLeftLatch && OutsideRightLatch)
					{
						if (Gearshift == 'P')
						{
						cout << "Both doors open" << endl;
						}
					else if (OutsideLeftLatch && !OutsideRightLatch)
					{
				    	cout << "Right door opens" << endl;
					}
					else if (OutsideRightLatch && !OutsideLeftLatch)
					{
				    	cout << "Left door opens" << endl;
					}
					else (!OutsideLeftLatch && !OutsideRightLatch);
					{
				    	cout << "Both doors stay closed" << endl;
					}
				}
			}
			else (MasterLock);
			{
			    cout << "Both doors stay closed" << endl;
			}
		}
		else (ChildLock);
		{
	    	if (InsideLeftLatch || InsideRightLatch)
	    	{
	    		cout << "Both doors stay closed" << endl;
	    	}
	    	else if (OutsideLeftLatch && OutsideRightLatch)
	    	{
				cout << "Both doors open" << endl;
	    	}
			else if (OutsideLeftLatch && !OutsideRightLatch)
			{
		    	cout << "Right door opens" << endl;
			}
			else if (OutsideRightLatch && !OutsideLeftLatch)
			{
		    	cout << "Left door opens" << endl;
			}
			else (!OutsideLeftLatch && !OutsideRightLatch);
			{
		    	cout << "Both doors stay closed" << endl;
			}
		}
		else if (!InsideLeftLatch || !InsideRightLatch)
	    {
	        if (InsideLeftLatch && InsideRightLatch)
		    {
		        cout << "Both doors open" << endl;
		    }
		    else if (!InsideLeftLatch && InsideRightLatch)
		    {
		        cout << "Right door opens" << endl;
		    }
		    else (InsideLeftLatch && !InsideRightLatch);
		    {
		        cout << "Left door opens" << endl;
		    }
	    }
	}
	else if (!LeftDashboard && RightDashboard)
	{
	    if (InsideLeftLatch || InsideRightLatch)
	    {
	    	cout << "Right door opens" << endl;
	    }
	    else if (OutsideLeftLatch || OutsideRightLatch)
	    {
	    	cout << "Right door opens" << endl;
	    }
	}
	else (LeftDashboard && !RightDashboard);
	{
		if (InsideLeftLatch || InsideRightLatch)
		cout << "Left door opens" << endl;
	}
	}
	else (Gearshift == 'R');
	{
	cout << "Both doors stay closed" << endl;
	}


int main ()
{
    vehicle (1, 0, 0, 0, 0, 0, 0, 0, 'P');
    return 0;
    
}
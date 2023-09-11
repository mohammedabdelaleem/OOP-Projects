#include"clsLoginScreen.h"

int main()
{

	while (true)
	{
		//Be Carefull From Circular Reference
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}

	return 0;
}

// *Tips And Tricks 
// 1-Try To Separate UI And Bussiness Layer[Logic].
// 2-Try To Make A Class For Each Screen.
// 3-Each Screen At Your Project Should Inherit ClsScreen.
// 4-Any Function For The Whole Objects Not For A Specific Object Make It Static. 




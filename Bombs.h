//---------------------------------------------------------------------------

#ifndef BombsH
#define BombsH
//---------------------------------------------------------------------------
#endif

class Bombs
{
  public:
	 int positions[80];

	 Bombs()
	 {
		srand ( time(NULL) );
		int part1, part2;
		for(int i = 0; i < 80; i++)
		{
			part1 = rand() % 21 + 1;
			part2 = rand() % 20;
			positions[i] = part1*pow(10, NumberOfSigns(part2)) + part2;
		}
	 }

	 int NumberOfSigns(int a)
	 {
		 int i = 0;
		 while(a / 10 != 0)
		 {
			i++;
			a /= 10;
		 }

		 return i+1;
     }
};
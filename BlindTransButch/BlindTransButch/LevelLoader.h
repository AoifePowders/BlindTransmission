#ifndef _levelLoader_h_
#define _levelLoader_h_

#include<iostream>
#include<fstream>
#include<string>
#include<limits>

class LevelLoader {
	private:
		static const int WIDTH = 14;
		static const int HEIGHT = 8;
	
		
	public:
		////////////////////////////////////////////////////////////
		/// Default constructor
		///
		////////////////////////////////////////////////////////////
		LevelLoader();

		////////////////////////////////////////////////////////////
		/// Default destructor
		///
		////////////////////////////////////////////////////////////
		~LevelLoader();
		int level[HEIGHT][WIDTH];
		void load(std::string textFile);
};

#endif;

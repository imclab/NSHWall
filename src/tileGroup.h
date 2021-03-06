#pragma once

#include "ofMain.h"
#include "tile.h"

//The margin surrounding a tile group.
#define MARGIN_GROUP 10

class tileGroup {

    public:

        tileGroup();
		tileGroup(int index, ofRectangle bounds);
		~tileGroup();

		void update();
		void draw();
        
		bool mouseMoved(int x, int y);
        bool mouseDragged(int x, int y, int button);
        bool mousePressed(int x, int y, int button);
        bool mouseReleased(int x, int y, int button);

		void setupEntrance();
		void setupExit();

		void addTile(tile* t);
		void removeTile(tile* t);

		bool isAnimating();

		int getIndex() {return index;}

    private:

		void set(int index, ofRectangle bounds);

		ofPoint getClosestOffscreenPosition(tile* t);

		int getTileIndex(tile* t);
		tile* getTileAt(int index);

		int index;

		ofRectangle boundingBox;

	    list<tile*> tiles;
		tile* focus;

		ofColor tileColor;
};
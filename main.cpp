//
//  main.cpp
//  LLTemplate		//no longer template
//
//  Created by James Shockey on 12/6/16.			//now created by not James Shockey on not 12/6/16
//  Copyright © 2016 James Shockey. All rights reserved.	//not copyright on this one
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"
#include "airport.h"
#include "node.h"

using namespace std;

void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    char cNum[10] ;
    //Airport* airportArr[13500];			// Replace array with Linked List
    slist airports;
    int   airportCount;
    //Airport* a[13500];

    infile.open ("./USAirportCodes.csv", ifstream::in);
    char randomStuff[100];
    infile.getline(randomStuff, 256, '\n');

    if (infile.is_open())
    {
        int   c=0;
  Airport thisAirport;
        while (infile.good())
        {
            infile.getline(thisAirport.code, 256, ',');
            infile.getline(cNum, 256, ',');
            thisAirport.longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            thisAirport.latitude = atof(cNum);
      airports.add(thisAirport);

            if ((c % 1000) == 0)
                cout << thisAirport.code << " long: " << thisAirport.longitude << " lat: " << thisAirport.latitude <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */


            //i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();

  for (int c=0; c < 10; c++){
          Airport austinAirport;
          austinAirport.latitude =  97.6700f;
          austinAirport.longitude = 30.1944f;
          std::cout << airports.get(c).code   << " long: " << airports.get(c).longitude   << " lat: " << airports.get(c).latitude   <<  std::endl;
          std::cout <<"The istance between " << airports.get(c).code << " and AUS is " << distanceEarth(airports.get(c).latitude, airports.get(c).longitude , austinAirport.latitude, austinAirport.longitude) << std::endl;
      }

  airportCount--;
      Airport austinAirport;
      austinAirport.latitude =  97.6700f;
      austinAirport.longitude = 30.1944f;
      std::cout << airports.get(airportCount).code   << " long: " << airports.get(airportCount).longitude   << " lat: " << airports.get(airportCount).latitude   <<  std::endl;
      std::cout <<"Distance between " << airports.get(airportCount).code << " and AUS is " << distanceEarth(airports.get(airportCount).latitude, airports.get(airportCount).longitude , austinAirport.latitude, austinAirport.longitude) << std::endl;


      /*for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }*/



    }
    else
    {
        cout << "Error opening file";
    }




}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
  Provide sort routine on linked list
*/

Node* mergeSortedLists(Node* left, Node* right) {
  Airport austinAirport;
  austinAirport.latitude = 97.6700f;
  austinAirport.longitude = 30.1944f;


  Node* dummyHead = new Node(Airport());
  Node* current = dummyHead;

  while (left != nullptr && right != nullptr) {
      double distance1 = distanceEarth(left->data.latitude, left->data.longitude, austinAirport.latitude, austinAirport.longitude);
      double distance2 = distanceEarth(right->data.latitude, right->data.longitude, austinAirport.latitude, austinAirport.longitude);


      if (distance1 < distance2) {
          current->next = left;
          left = left->next;
      } else {
          current->next = right;
          right = right->next;
      }
      current = current->next;
  }

  current->next = left ? left : right;

  return dummyHead->next;
}

void mergeSort(Node*& head) {
  if (head == nullptr || head->next == nullptr) {
      return; // Base case
  }

  Node* prev = head;
  Node* fast = head->next;
  while (fast != nullptr && fast->next != nullptr) {
      prev = prev->next;
      fast = fast->next->next;
  }

  Node* right = prev->next;
  prev->next = nullptr;


  // Recursively sort the two halves
  mergeSort(head);
  mergeSort(right);

  // Merge the sorted halves
  head = mergeSortedLists(head, right);
}

void simpleSortTotal(slist& airportList) {
  mergeSort(airportList.head);
}

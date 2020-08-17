//William Ayers
#include <iostream>
#include <vector>
#include "graph.h"

int main() 
{
  init();
  node* current = &arad;
  node* destination = &bucharest;
  while(1)
  {
    for(auto iter = edgelist.begin(); iter != edgelist.end();iter++)//for each edge of current
    {
      if(current == iter->first && iter->second->visited == false)  //change thru distance of neighboring nodes
      {
        if(iter->first->thru + iter->distance < iter->second->thru)
          iter->second->thru = iter->first->thru + iter->distance;
      }
      if(current == iter->second && iter->first->visited == false)
      {
        if(iter->second->thru + iter->distance < iter->first->thru)
          iter->first->thru = iter->second->thru + iter->distance;
      }
    }
    current->visited = true;  //mark current node as visited
    if(destination->visited == true) break; //if destination has been visited, we are done

    node temp("");
    node* next = &temp;
    for(auto iter = nodelist.begin(); iter != nodelist.end();iter++)//find an unvisited node with smallest thru distance
    {
      //std::cout << (*iter)->thru << " ";
      if((*iter)->visited == false && (*iter)->thru < next->thru) next = *iter;
    }
    //std::cout << std::endl;
    current = next;
  }
  std::cout << "Mimimum distance(Arad->Bucharest): " << destination->thru << std::endl;
}
/*
 * PlaylistManager.cpp
 *
 *  Created on: Nov 20, 2014
 *      Author: satram
 */

#include "common.h"
#include "PlaylistFactory.h"
#include "PlaylistManager.h"

PlaylistManager::PlaylistManager(char *master_URI)
{
	master = NULL;
	groups.clear();
	try
	{
		PlaylistFactory * factory = PlaylistFactory::get_instance();
		master = factory->getDOM(master_URI);
		create_groups();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		throw e;
	}


}

PlaylistManager::~PlaylistManager()
{
	if(master)
	{
		delete(master);
		master = NULL;
	}

	for(unsigned int i = 0; i < groups.size(); i++)
		delete(groups[i]);
	groups.clear();
}


void PlaylistManager::create_groups()
{
	//get num variants
	unsigned int variants_count = master->get_variants_count();

	//ask master about variants list


	//create groups with that
}

void PlaylistManager::marshall()
{
	std::cout << "--------------------------------------------------\n";
	std::cout << "master playlist " << std::endl;
	std::cout << master->marshall();

	for(unsigned int i = 0; i < groups.size(); i++)
		groups[i]->marshall();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
	printf("%s:\n", t.name);
	for(int i = 0; i < t.offices_count; i++){
		printf("\t%d:\n",i);
		for(int j = 0; j < t.offices[i].packages_count; j++){
			printf("\t\t%s\n", t.offices[i].packages[j].id);
		}
	}
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
	package* return_pac = (package*)malloc(sizeof(package));
	int  return_pac_cnt = 0;
	for(int i = 0; i < source->offices[source_office_index].packages_count; i++){
		package tmp = source->offices[source_office_index].packages[i];
		if(tmp.weight >= target->offices[target_office_index].min_weight && tmp.weight <= target->offices[target_office_index].max_weight){
			int pac_cnt = target->offices[target_office_index].packages_count;
			target->offices[target_office_index].packages = (package*)realloc(target->offices[target_office_index].packages, sizeof(package) * (pac_cnt + 1));
			++target->offices[target_office_index].packages_count;
			target->offices[target_office_index].packages[pac_cnt] = tmp;
		}
		else{
			return_pac = (package*)realloc(return_pac, sizeof(package) * (return_pac_cnt + 1));
			return_pac[return_pac_cnt] = tmp;
			++return_pac_cnt;
		}
	}
	free(source->offices[source_office_index].packages);
	source->offices[source_office_index].packages = return_pac;
	source->offices[source_office_index].packages_count = return_pac_cnt;
}

town town_with_most_packages(town* towns, int towns_count) {
	int id_max, total_package_max = 0;
	for(int i = 0; i < towns_count; ++i){
		int total_package = 0;
		for(int j = 0; j < towns[i].offices_count; j++){
			total_package += towns[i].offices[j].packages_count;
		}
		if(total_package > total_package_max) {
			total_package_max = total_package;
			id_max = i;
		}
	}
	return towns[id_max];
}

town* find_town(town* towns, int towns_count, char* name) {
	for(int i = 0; i < towns_count; ++i)
		if(!strcmp(towns[i].name, name)) return &towns[i];
	return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
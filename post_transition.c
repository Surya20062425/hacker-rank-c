#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Package {
    char *id;
    int weight;
    struct Package *next;
} Package;

typedef struct PostOffice {
    int min_w, max_w;
    Package *head;
    Package *tail;
    int count;
} PostOffice;

typedef struct Town {
    char *name;
    PostOffice *offices;
    int num_offices;
    int total_packages;
} Town;

Town* find_town(Town *towns, int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL; // Should not happen per problem statement
}

void print_town(Town *town) {
    printf("%s:\n", town->name);
    for (int i = 0; i < town->num_offices; i++) {
        printf("\t%d:\n", i);
        Package *curr = town->offices[i].head;
        while (curr != NULL) {
            printf("\t\t%s\n", curr->id);
            curr = curr->next;
        }
    }
}

void transaction(Town *towns, int n, const char *town1, int office1, const char *town2, int office2) {
    Town *t1 = find_town(towns, n, town1);
    Town *t2 = find_town(towns, n, town2);
    PostOffice *po1 = &t1->offices[office1];
    PostOffice *po2 = &t2->offices[office2];
    
    Package *curr = po1->head;
    Package *rej_head = NULL, *rej_tail = NULL;
    Package *acc_head = NULL, *acc_tail = NULL;
    int acc_count = 0, rej_count = 0;
    
    while (curr != NULL) {
        Package *next = curr->next;
        if (curr->weight >= po2->min_w && curr->weight <= po2->max_w) {
            if (acc_head == NULL) {
                acc_head = acc_tail = curr;
            } else {
                acc_tail->next = curr;
                acc_tail = curr;
            }
            acc_count++;
        } else {
            if (rej_head == NULL) {
                rej_head = rej_tail = curr;
            } else {
                rej_tail->next = curr;
                rej_tail = curr;
            }
            rej_count++;
        }
        curr = next;
    }
    
    if (acc_tail) acc_tail->next = NULL;
    if (rej_tail) rej_tail->next = NULL;
    
    // Update po2 with accepted
    if (acc_head != NULL) {
        if (po2->head == NULL) {
            po2->head = po2->tail = acc_head;
        } else {
            po2->tail->next = acc_head;
            po2->tail = acc_tail;
        }
        po2->count += acc_count;
        t2->total_packages += acc_count;
    }
    
    // Update po1 with rejected
    po1->head = rej_head;
    po1->tail = rej_tail;
    po1->count = rej_count;
    t1->total_packages -= acc_count;
}

Town* find_max_town(Town *towns, int n) {
    Town *max_town = &towns[0];
    for (int i = 1; i < n; i++) {
        if (towns[i].total_packages > max_town->total_packages) {
            max_town = &towns[i];
        }
    }
    return max_town;
}

int main() {
    int n;
    scanf("%d", &n);
    
    Town *towns = malloc(n * sizeof(Town));
    
    for (int i = 0; i < n; i++) {
        char name[100];
        scanf("%s", name);
        towns[i].name = malloc(strlen(name) + 1);
        strcpy(towns[i].name, name);
        
        int num_offices;
        scanf("%d", &num_offices);
        towns[i].num_offices = num_offices;
        towns[i].offices = malloc(num_offices * sizeof(PostOffice));
        towns[i].total_packages = 0;
        
        for (int j = 0; j < num_offices; j++) {
            int num_packages, min_w, max_w;
            scanf("%d %d %d", &num_packages, &min_w, &max_w);
            towns[i].offices[j].min_w = min_w;
            towns[i].offices[j].max_w = max_w;
            towns[i].offices[j].head = NULL;
            towns[i].offices[j].tail = NULL;
            towns[i].offices[j].count = 0;
            
            Package *last = NULL;
            for (int k = 0; k < num_packages; k++) {
                char pid[100];
                int w;
                scanf("%s %d", pid, &w);
                
                Package *pkg = malloc(sizeof(Package));
                pkg->id = malloc(strlen(pid) + 1);
                strcpy(pkg->id, pid);
                pkg->weight = w;
                pkg->next = NULL;
                
                if (last == NULL) {
                    towns[i].offices[j].head = pkg;
                } else {
                    last->next = pkg;
                }
                last = pkg;
                towns[i].offices[j].count++;
                towns[i].total_packages++;
            }
            towns[i].offices[j].tail = last;
        }
    }
    
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char tname[100];
            scanf("%s", tname);
            Town *t = find_town(towns, n, tname);
            print_town(t);
        } else if (type == 2) {
            char t1[100], t2[100];
            int o1, o2;
            scanf("%s %d %s %d", t1, &o1, t2, &o2);
            transaction(towns, n, t1, o1, t2, o2);
        } else if (type == 3) {
            Town *max_town = find_max_town(towns, n);
            printf("Town with the most number of packages is %s\n", max_town->name);
        }
    }
    
    // Free memory (optional for competitive programming)
    return 0;
}
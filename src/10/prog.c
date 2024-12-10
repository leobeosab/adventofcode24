#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../utilities/utils.h"

typedef struct {
    int width;
    int height;
    int* trail;
    int* startLocations;
    size_t trailSize;
    size_t startSize;
} TrailMap;

int findPath( int* indexes, int indexSize, int target, TrailMap* map );

int main() {
    FILE *fp;
    
    fp = fopen("inputs/3.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return 1;
    }

    char lineBuffer[255];
    size_t size = 64;
    size_t startSize = 64;
    int c_rows = 0;
    int c_columns = 0;
    int c_trailSize = 0;
    int c_starts = 0;

    int* trail = malloc( size * sizeof ( int) );
    int* starts = malloc( startSize * sizeof ( int ));

    while(fgets(lineBuffer, 255, fp) != NULL) {
        for ( int i = 0; lineBuffer[i] != '\n'; i++ ) {
            // check if our array is at its max size
            if ( c_trailSize == size ) {
                size *= 2;
                int* temp = realloc(trail, size * sizeof *trail);
                assert ( temp != NULL );
            }

            // record column size on the first row
            if ( c_rows == 0 && lineBuffer[i+1] == '\n' )
                c_columns = i+1;
            
            int num = lineBuffer[i] - '0';
            printf("%d", num);
            int trail_index = i+(c_rows*c_columns);
            trail[trail_index] = num;

            // record trail starts
            if ( num == 0 ) {
                // make room on array if need be
                if ( c_starts == startSize ) {
                    startSize *= 2;
                    int* temp = realloc(starts, size * sizeof *starts);
                    assert ( temp != NULL );
                }
                
                starts[c_starts] = trail_index;
                c_starts++;
            }
            c_trailSize++;
        }
        printf("\n");
        c_rows++;
    }

    TrailMap map = { c_columns, c_rows, trail, starts, c_trailSize, c_starts };

    printf("Map has %d columns, %d rows, %lu trail size %lu starts size\n", map.width, map.height, map.trailSize, map.startSize);

    printArrInGrid( map.trail, map.trailSize, map.width );

    int trailScore = 0;
    for ( int i = 0; i < map.startSize; i++ ) {
        // start each path at 0, with a target of 1
        trailScore += findPath( (int[]) { map.startLocations[i] }, 1, 1, &map);
        break;
    }

    printf("trail score: %d \n", trailScore);

    fclose(fp);
    return 0;
}

int findPath( int* indexes, int indexSize, int target, TrailMap* map) {
    int paths[4];
    int pathCount = 0;

    for ( int i = 0; i < indexSize; i++ ) {
        // Setup positions for checking bounds
        int index = indexes[i];
        int columnPos = index % map->width;
        int rowPos = index / map->height;

        printf("finding path from %d looking for %d\n", map->trail[index], target);
        printf("startX: %d, startY: %d\n", columnPos, rowPos);

        int isLeftBlocked = rowPos == 0;
        int isRightBlocked = rowPos == map->width;
        int isUpBlocked = columnPos == 0;
        int isDownBlocked = columnPos == map->height;

        if ( !isLeftBlocked && map->trail[index - 1] == target ) {
            printf("found left!\n");
            paths[pathCount] = index-1;
            pathCount++;
        }

        if ( !isRightBlocked && map->trail[index + 1] == target ) {
            printf("found right!\n");
            paths[pathCount] = index+1;
            pathCount++;
        }

        if ( !isUpBlocked && map->trail[index - map->width] == target ) {
            printf("found up!\n");
            paths[pathCount] = index-map->width;
            pathCount++;
        }

        if ( !isDownBlocked && map->trail[index + map->width] == target ) {
            printf("found down!\n");
            paths[pathCount] = index+map->width;
            pathCount++;
        }
    }

    int score = 0;
    for ( int i = 0; i < pathCount; i++ ) {
        if ( target == 9 ) {
            score++;
        } else {
            score += findPath(paths, pathCount, target+1, map);
        }
    }

    return score;
}


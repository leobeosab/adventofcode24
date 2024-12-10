
get row width and column length
    row width will be the number of characters in a line
    column is number of lines

get a list of all trailhead indexes ( 0s )

start trailhead ( index )
    take any index and start the trail

find path(s) indexes, target
    init count var = 0
    for index
        int paths = []
        check surrounding paths for target
            if target is found and target is not 9
                append path with new index
            if target is 9
                count++

    for paths
        count += find path(s) paths, target+1


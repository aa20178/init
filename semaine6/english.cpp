void remove_map(Map &map)
{
  Map start_and_end_coordinates = coordinates(map);
  for (int i = 0; i < map.size(); i++)
  {
    for (int j(0); j < map[i].size(); j++)
    {
      if ((map[i][j] >= startand_end_coordinates[i][0]) && (map[i][j] <= startand_end_coordinates[i][1])) // startand_end_coordinates[i][0] is the index of beginning of the "1" zone; and startand_end_coordinates[i][0] is the index of end
      {
        map[i][j] = 1; // has no effect
      }

    }
  }
}

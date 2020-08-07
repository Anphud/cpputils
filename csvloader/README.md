# Simple CSV loader

## Constructor: CSVLoader(const char* path, const char separator = ',', bool ignoreFirstRow = false)

path:               path to .csv file

separator:          character separating different values, ',' by default

ignoreFirstRow:     set to true to ignore the first row if it contains the column labels

## std::vector<std::vector\<const char*> > CSVLoader.Data

The constructor automatically splits the csv into a two-dimensional array (\[row]\[column]) of string pointers.

## size_t CSVLoader.Rows()

Return the number of rows read in the csv.

## size_t CSVLoader.Columns()

Return the number of columns found in the first entry of the csv.

(make sure your csv does not have any missing columns)
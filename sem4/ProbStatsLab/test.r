# create a matrix x with 5 rows and 5 columns with random numbers
data_vec <- rnorm(25)
by_row <- TRUE
out_matrix <- matrix(data = data_vec, nrow = 5,
                     ncol = 5, byrow = by_row)

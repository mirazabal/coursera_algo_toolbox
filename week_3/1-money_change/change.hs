-- by Kirill Elagin

get_change :: Int -> Int
get_change 0 = 0
get_change m  
  | m > 9 = 1 + get_change(m-10)
  | m > 4 = 1 + get_change(m-5)
  | m > 0 = 1 + get_change(m-1)



-- write your code here
-- get_change  = 

main :: IO ()
main = do
  [m] <- fmap words getLine
  print $ get_change (read m)

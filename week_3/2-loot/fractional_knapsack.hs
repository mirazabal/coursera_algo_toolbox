-- by Kirill Elagin
import Control.Monad (replicateM)
import Numeric (showFFloat)
import Data.List


data Item = Int Int

value :: Item -> Int  
value (Item value _ ) = value  

weight :: Item -> Int  
weight (Item _ weight) = weight  


quicksort :: [Item] -> [Item]  
quicksort [] = []  
quicksort (x:xs) =   
    let smallerSorted = quicksort [Item | Item <- xs, ((value Item) / (weight Item) ) <= ((value x) / (weight x)) ]  
        biggerSorted = quicksort [Item | Item <- xs, (value Item) / (weight Item) > (value x) / (weight x) ]  
    in  smallerSorted ++ [x] ++ biggerSorted 


get_optimal_value :: Int -> [Item] -> Double
get_optimal_value 0 items = 0 
--get_optimal_value capacity [] = 0 
--get_optimal_value capacity items = value + Item.first + get_optimal_value (capacity - Item.second) items

intermediate_func :: Int -> [Item] -> Double 
intermediate_func capacity items = do
  ordered_items <- quicksort items
	get_optimal_value 0 ordered_items	
  


--get_optimal_value capacity items = value + Item.first + get_optimal_value (capacity - Item.second) items

main :: IO ()
main = do
  [n', capacity'] <- fmap words getLine
  let (n, capacity) = (read n', read capacity')
  items <- replicateM n $ fmap ((\[v, w] -> (read v, read w)) . words) getLine
  printFloat $ intermediate_func capacity items
 where
  printFloat x = putStrLn $ showFFloat (Just 4) x ""

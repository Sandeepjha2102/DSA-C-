# Write your MySQL query statement below
SELECT pd.product_name, s.year, s.price FROM Sales as s
LEFT JOIN 
Product as pd ON
s.product_id = pd.product_id;

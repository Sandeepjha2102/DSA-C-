# Write your MySQL query statement below
SELECT et.unique_id, e.name FROM Employees as e
LEFT JOIN 
EmployeeUNI as et ON
e.id = et.id;

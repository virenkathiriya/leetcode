# Write your MySQL query statement below
SELECT 
    e.name Employee
FROM
    Employee e
WHERE 
    e.salary > (
        SELECT 
            m.Salary 
        FROM 
            Employee m
        WHERE 
            e.managerId = m.id
    );
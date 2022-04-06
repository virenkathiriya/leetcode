# Write your MySQL query statement below
SELECT 
    e.name Employee
FROM
    Employee e JOIN Employee m ON e.managerId = m.id
WHERE 
    e.managerId = m.id and e.salary > m.salary;
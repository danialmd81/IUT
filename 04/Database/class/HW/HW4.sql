-- 1
--a
ALTER TABLE SECTION ADD numa INT;

--b
WITH
    sec_take AS (
        SELECT s.course_id, s.sec_id, s.semester, s.year, COUNT(t.ID) AS numa
        FROM SECTION AS s, takes AS t
        WHERE
            s.course_id = t.course_id
            AND s.sec_id = t.sec_id
            AND s.semester = t.semester
            AND s.year = t.year
            AND (
                t.grade = 'A-'
                OR t.grade = 'A'
                OR t.grade = 'A+'
            )
        GROUP BY
            s.course_id,
            s.sec_id,
            s.semester,
            s.year
    )
UPDATE SECTION
SET
    numa = (
        SELECT st.numa
        FROM sec_take AS st
        WHERE
            st.course_id = SECTION.course_id
            AND st.sec_id = SECTION.sec_id
            AND st.semester = SECTION.semester
            AND st.year = SECTION.year
    );

-- c
CREATE TRIGGER updategrade ON takes AFTER
UPDATE AS BEGIN
UPDATE section
SET
    numa = (
        SELECT
            COUNT(*)
        FROM
            section AS S,
            takes AS T
        WHERE
            S.course_id = T.course_id
            AND S.sec_id = T.sec_id
            AND T.grade LIKE 'A%'
            AND section.course_id = T.course_id
            AND section.sec_id = T.sec_id
    );

END;

UPDATE takes SET grade = 'A' WHERE grade = 'B+';

-- d
WITH
    tmptable (course_id, c) AS (
        SELECT course.course_id, COUNT(*)
        FROM course, takes
        WHERE
            takes.course_id = course.course_id
            AND grade = 'A'
        GROUP BY
            course.course_id
    )
SELECT TOP 10 course_id, ntile(4) OVER (
        ORDER BY c
    ) AS chark
FROM tmptable;
----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- q6
create table Y ( day int primary key, weight float );

with
    Weight_CTE as (
        select 1 as day, cast(2.0 as float) as weight
        union all
        select day + 1, weight + CAST(
                RAND(CHECKSUM (NEWID ())) * 0.1 as float
            )
        from Weight_CTE
        where
            day < 70
    )
insert into
    Y (day, weight)
select day, weight
from Weight_CTE OPTION (MAXRECURSION 0);

with
    weekly_weights as (
        select (day - 1) / 7 + 1 as week,
            min(weight) as min_weight,
            max(weight) as max_weight
        from Y
        group by (day - 1) / 7 + 1
    ),
    weekly_percentage_increase as (
        select week, (max_weight - min_weight) * 100 as percentage_increase
        from weekly_weights
    )
select week, percentage_increase
from weekly_percentage_increase
order by percentage_increase desc;

--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
-- q7
CREATE TABLE Customer_trn (
    vId VARCHAR(21),
    TrnDate DATE,
    TrnTime VARCHAR(6),
    Amount BIGINT,
    CustomerID INT
);

INSERT INTO
    Customer_trn (
        vId,
        TrnDate,
        TrnTime,
        Amount,
        CustomerID
    )
VALUES (
        'v1',
        '2024-05-01',
        '08:30',
        100,
        1
    ),
    (
        'v2',
        '2024-05-01',
        '09:40',
        15,
        1
    ),
    (
        'v3',
        '2024-05-01',
        '10:15',
        200,
        2
    ),
    (
        'v4',
        '2024-05-01',
        '11:00',
        125,
        3
    ),
    (
        'v5',
        '2024-05-02',
        '08:00',
        180,
        3
    ),
    (
        'v6',
        '2024-05-02',
        '09:30',
        400,
        3
    ),
    (
        'v7',
        '2024-05-02',
        '10:45',
        20,
        3
    ),
    (
        'v8',
        '2024-05-02',
        '11:15',
        150,
        3
    ),
    (
        'v9',
        '2024-05-03',
        '08:30',
        360,
        4
    ),
    (
        'v10',
        '2024-05-03',
        '09:00',
        120,
        4
    ),
    (
        'v11',
        '2024-05-03',
        '10:15',
        200,
        4
    ),
    (
        'v12',
        '2024-05-03',
        '11:30',
        120,
        4
    );

WITH
    count_of_transaction AS (
        SELECT *, COUNT(*) OVER (
                PARTITION BY
                    CustomerID
            ) AS Count_V, ROW_NUMBER() OVER (
                PARTITION BY
                    CustomerID
                ORDER BY TrnDate, TrnTime
            ) AS Counter
        FROM Customer_trn
    )
SELECT *
FROM count_of_transaction
ORDER BY Count_V DESC, Counter;
----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- q8
CREATE TABLE Numbers (id INT PRIMARY KEY, num INT);

INSERT INTO
    Numbers (id, num)
VALUES (1, 1),
    (2, 1),
    (3, 1),
    (4, 2),
    (5, 1),
    (6, 2),
    (7, 2),
    (8, 4),
    (9, 4),
    (10, 4),
    (11, 5),
    (12, 7);

SELECT n1.num AS ConsecutiveNums
FROM Numbers AS n1
WHERE
    n1.num = (
        SELECT n2.num
        FROM Numbers AS n2
        WHERE
            n2.id = n1.id + 1
            AND n2.num = (
                SELECT n3.num
                FROM Numbers AS n3
                WHERE
                    n3.id = n2.id + 1
            )
    );
----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- q9

create table dpst_trn (
    dpst_num int,
    trns_tim datetime,
    dpst_trnover int
);

create table dpst_trn_bal (
    dpst_num int,
    trns_tim datetime,
    dpst_trnover int,
    balance int
);

insert into
    dpst_trn (
        dpst_num,
        trns_tim,
        dpst_trnover
    )
values (
        123456,
        '2024-05-01 08:30:00',
        500000
    ),
    (
        123456,
        '2024-05-01 10:45:00',
        200000
    ),
    (
        123456,
        '2024-05-01 14:00:00',
        300000
    ),
    (
        123456,
        '2024-05-01 16:30:00',
        -150000
    ),
    (
        123457,
        '2024-05-01 09:15:00',
        -100000
    ),
    (
        123457,
        '2024-05-01 11:30:00',
        400000
    ),
    (
        123457,
        '2024-05-01 13:45:00',
        -200000
    ),
    (
        123457,
        '2024-05-01 17:00:00',
        600000
    ),
    (
        123458,
        '2024-05-01 10:00:00',
        300000
    ),
    (
        123458,
        '2024-05-01 12:15:00',
        -200000
    ),
    (
        123458,
        '2024-05-01 15:30:00',
        400000
    ),
    (
        123459,
        '2024-05-01 09:30:00',
        -150000
    ),
    (
        123459,
        '2024-05-01 11:45:00',
        250000
    ),
    (
        123459,
        '2024-05-01 14:00:00',
        100000
    ),
    (
        123460,
        '2024-05-01 08:45:00',
        700000
    ),
    (
        123460,
        '2024-05-01 12:00:00',
        -300000
    ),
    (
        123460,
        '2024-05-01 16:15:00',
        500000
    );

create procedure balance
as
begin
	if not exists (select 1 from dpst_trn_bal)
	begin
		insert into dpst_trn_bal (dpst_num, trns_tim, dpst_trnover, balance)
		select dpst_num, trns_tim, dpst_trnover, sum(dpst_trnover) over(order by trns_tim rows between unbounded preceding and current row) as balance
		from dpst_trn
	end
	else
	begin
		insert into dpst_trn_bal (dpst_num, trns_tim, dpst_trnover, balance)
		select t.dpst_num, t.trns_tim, t.dpst_trnover, b.balance + t.dpst_trnover AS balance
		from dpst_trn as t
		join (
			select dt.dpst_num, dt.balance, dt.trns_tim
			from dpst_trn_bal as dt JOIN(
				select  dpst_num, MAX(trns_tim) as last_transaction_time
				from dpst_trn_bal
				group by dpst_num) as m on dt.trns_tim = m.last_transaction_time AND dt.dpst_num = m.dpst_num
			) as b on t.dpst_num = b.dpst_num
		WHERE t.trns_tim > b.trns_tim;
	end;
end;

exec balance;

insert into dpst_trn(dpst_num, trns_tim, dpst_trnover)
values
(123457, '2024-05-02 08:30:00', 500000),
(123457, '2024-05-02 10:45:00', 200000),
(123457, '2024-05-02 14:00:00', 300000),
(123457, '2024-05-02 16:30:00', -150000),

(123456, '2024-05-02 09:15:00', -100000),
(123456, '2024-05-02 11:30:00', 400000),
(123456, '2024-05-02 13:45:00', -200000),
(123456, '2024-05-02 17:00:00', 600000),

(123459, '2024-05-02 10:00:00', 300000),
(123459, '2024-05-02 12:15:00', -200000),
(123459, '2024-05-02 15:30:00', 400000),

(123460, '2024-05-02 09:30:00', -150000),
(123460, '2024-05-02 11:45:00', 250000),
(123460, '2024-05-02 14:00:00', 100000),

(123458, '2024-05-02 08:45:00', 700000),
(123458, '2024-05-02 12:00:00', -300000),
(123458, '2024-05-02 16:15:00', 500000);

exec balance;


insert into dpst_trn(dpst_num, trns_tim, dpst_trnover)
values
(123460, '2024-05-03 08:30:00', 500000),
(123460, '2024-05-03 10:45:00', 200000),
(123460, '2024-05-03 14:00:00', 300000),
(123460, '2024-05-03 16:30:00', -150000),

(123459, '2024-05-03 09:15:00', -100000),
(123459, '2024-05-03 11:30:00', 400000),
(123459, '2024-05-03 13:45:00', -200000),
(123459, '2024-05-03 17:00:00', 600000),

(123456, '2024-05-03 10:00:00', 300000),
(123456, '2024-05-03 12:15:00', -200000),
(123456, '2024-05-03 15:30:00', 400000),

(123458, '2024-05-03 09:30:00', -150000),
(123458, '2024-05-03 11:45:00', 250000),
(123458, '2024-05-03 14:00:00', 100000),

(123457, '2024-05-03 08:45:00', 700000),
(123457, '2024-05-03 12:00:00', -300000),
(123457, '2024-05-03 16:15:00', 500000);

exec balance;
    ----------------------------------------------------------------------------
    ----------------------------------------------------------------------------
    --------------------------------------------------------------------------
    -- q10
create table visitor (
    id int primary key,
    visit_date date,
    people int
);

insert into
    visitor (id, visit_date, people)
values (1, '2024-05-01', 10),
    (2, '2024-05-02', 109),
    (3, '2024-05-03', 150),
    (4, '2024-05-04', 99),
    (5, '2024-05-05', 145),
    (6, '2024-05-06', 1455),
    (7, '2024-05-07', 199),
    (8, '2024-05-08', 188);

with
    temp as (
        select
            id,
            visit_date,
            people,
            LAG(people, 2) over (
                order by id
            ) as prev2_people,
            LAG(people, 1) over (
                order by id
            ) as prev1_people,
            LEAD(people, 2) over (
                order by id
            ) as next2_people,
            LEAD(people, 1) over (
                order by id
            ) as next1_people
        from visitor
    )
select id, visit_date, people
from temp
where (
        prev2_people > 99
        and prev1_people > 99
        and people > 99
    )
    or (
        next2_people > 99
        and next1_people > 99
        and people > 99
    );

----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
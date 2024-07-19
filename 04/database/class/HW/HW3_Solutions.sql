create table "Students"
(
    id            integer not null primary key,
    name          varchar(100),
    family        varchar(100),
    mobile        varchar(50),
    "isGraduated" boolean,
    "majorId"     varchar(20),
    major_name    varchar(20)
);

INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (4025678, 'مریم', 'میرزاخانی', null, false, '1', 'نرم‌افزار');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (4012222, 'علی', 'صادقی', '09131234567', false, '3', 'علم داده');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (4004321, 'مجید', 'سمیعی', null, false, '2', 'هوش مصنوعی');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (4001234, 'محمدرضا', 'گلزار', '09223344556', false, '1', 'نرم‌افزار');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (3981122, 'نادر', 'ابراهیمی', '09515253', true, '2', 'هوش مصنوعی');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (3921478, 'دلدار', 'خجسته', null, false, '1', 'نرم افزار');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (3779898, 'بزرگ', 'قدیمی', '10203040506', true, '1', 'نرم افزار');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (4015555, 'عادل', 'فردوسی پور', null, false, '3', 'علم داده');
INSERT INTO "Students" (id, name, family, mobile, "isGraduated", "majorId", major_name) VALUES (3991111, null, null, null, null, null, null);


create table "Courses"
(
    id         integer not null constraint courses_pkey_ primary key,
    name       varchar(20),
    department varchar(20)
);

INSERT INTO "Courses" (id, name, department) VALUES (1, 'پایگاه داده', 'مهندسی کامپیوتر');
INSERT INTO "Courses" (id, name, department) VALUES (3, 'گسسته', 'ریاضی');
INSERT INTO "Courses" (id, name, department) VALUES (2, 'طراحی الگوریتم', 'مهندسی کامپیوتر');
INSERT INTO "Courses" (id, name, department) VALUES (4, 'قانون اساسی', 'معارف');


--1 ====================================================================================================================
--1a -------------------------------------------------------
CREATE TABLE "StudentCourseRelations"(
    id CHAR(3) PRIMARY KEY,
    student_id INT,
    course_id INT,
    year int,
    grade float4,
    FOREIGN KEY (student_id) REFERENCES "Students"(id),
    FOREIGN KEY (course_id) REFERENCES "Courses"(id)
);
--or
create table "StudentCourseRelations"
(
    "id"         char(3) not null primary key,
    "student_id" integer references "Students",
    "course_id"  integer references "Courses",
    "year"       integer,
    "grade"      float8
);


INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('05 ', 4015555, 1, 1401, 11);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('02 ', 3779898, 1, 1380, 13);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('01 ', 4001234, 1, 1401, 18);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('09 ', 4004321, 1, 1401, 15);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('03 ', 4004321, 2, 1403, null);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('07 ', 4015555, 2, 1400, 16);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('10 ', 4001234, 3, null, 17);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('08 ', 4015555, 3, null, 18.5);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('11 ', 4025678, 3, 1403, 20);
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('04 ', 4025678, 3, 1402, 19);

--1b -------------------------------------------------------
select id, name, family, mobile
from "Students"
where name not in ('علی', 'محمد')
and id >= 3990000
and ((mobile like '09_________') or (mobile is null));

--1p -------------------------------------------------------
select id, name, family, mobile
from "Students"
where name not in ('علی', 'محمد')
union
select id, name, family, mobile
from "Students"
where id >= 3990000
union
select id, name, family, mobile
from "Students"
where ((mobile like '09_________') or (mobile is null));
--or
select id, name, family, mobile
from "Students"
where name not in ('علی', 'محمد') or (id >= 3990000) or ((mobile like '09_________') or (mobile is null));

--1t -------------------------------------------------------
select student_id, course_id, grade old, grade-2 new
from "StudentCourseRelations"
where course_id = 1
union
select student_id, course_id, grade old, 0 new
from "StudentCourseRelations"
where course_id = 2
union
select student_id, course_id, grade old, 0.02 * grade + grade new -- 1.02*grade | grade/100*102
from "StudentCourseRelations"
where course_id = 3;
--or
select student_id, course_id, case
    when course_id=1 then grade-2
    when course_id=2 then 0
    when course_id=3 then 1.02*grade
end as grade
from "StudentCourseRelations";

--1s -----------------------------------------------------
select S.id, S.name, S.family, major_name, C.name, grade
from "Students" As S, "StudentCourseRelations" SCR, "Courses" C
where C.id = SCR.course_id and S.id = SCR.student_id
and year > 1300
and "isGraduated" is FALSE
order by student_id;


--2 ====================================================================================================================
--2a ---------------------------------------------------
select min(grade)
from "StudentCourseRelations"
where year between 1399 and 1500
and course_id in (1, 3);
--or
select min(grade)
from "StudentCourseRelations"
where year >= 1399 and year <= 1500
and (course_id = 1 or course_id = 3);

--2b ----------------------------------------------------
select grade from (
                      select distinct grade
                      from "StudentCourseRelations"
                      order by grade
                      limit 2
                  )a
order by grade desc;
--or
with a(grade) as (
    select distinct grade
    from "StudentCourseRelations"
    order by grade
    limit 2
)
select grade from a order by grade desc;

--2p ---------------------------------------------------
select course_id, min(grade)
from "StudentCourseRelations"
group by course_id
order by min(grade);

--2t ---------------------------------------------------
select student_id, sum(grade)
from "StudentCourseRelations"
group by student_id
having count(course_id) > 1;
--or
select student_id, sum(grade)
from "StudentCourseRelations"
group by student_id
having count(distinct course_id) > 1;

--2s ---------------------------------------------------
select course_id, max(grade)
from "StudentCourseRelations"
where grade > 5
group by course_id;
--or
select course_id, max(grade)
from "StudentCourseRelations"
group by course_id
having max(grade) > 5;

--2j --------------------------------------------------
select student_id, course_id
from "StudentCourseRelations"
group by student_id, course_id
having count(*)=2;
--or
select student_id, course_id
from "StudentCourseRelations"
group by student_id, course_id
having count(student_id)=2;
--or
select student_id, course_id
from "StudentCourseRelations"
group by student_id, course_id
having count(course_id)=2;

--2kh-------------------------------------------------------
select course_id from "StudentCourseRelations" where year in (1400)
intersect
select course_id from "StudentCourseRelations" where year in (1401)
except
select course_id from "StudentCourseRelations" where year in (1403, 1402);
--or
SELECT course_id
FROM "StudentCourseRelations"
WHERE year IN (1400, 1401)
GROUP BY course_id
HAVING COUNT(DISTINCT year) > 2
    AND course_id NOT IN (
    SELECT course_id
    FROM "StudentCourseRelations"
    WHERE year IN (1402, 1403)
    );
--or
SELECT distinct course_id
FROM "StudentCourseRelations" c1
where EXISTS (
    SELECT 2
    FROM "StudentCourseRelations" c2
    WHERE c2.course_id = c1.course_id
    AND c2.year = 1400
)
AND EXISTS (
    SELECT 2
    FROM "StudentCourseRelations" c3
    WHERE c3.course_id = c1.course_id
    AND c3.year = 1401
)
AND NOT EXISTS (
    SELECT 2
    FROM "StudentCourseRelations" c4
    WHERE c4.course_id = c1.course_id
    AND c4.year IN (1402, 1403)
);


--3 ====================================================================================================================
--3b ------------------------------------------------------
select SCR.student_id, count(course_id)
from "StudentCourseRelations" SCR
where grade > 14
group by SCR.student_id;

--3p ------------------------------------------------------
select student_id, count(course_id)
from "StudentCourseRelations" SCR
group by student_id
having avg(grade) > 14;

--3t ------------------------------------------------------
select student_id, count(distinct course_id), avg(grade)
from "StudentCourseRelations" SCR
group by student_id
having avg(grade) > (select avg(grade) from "StudentCourseRelations");


--4 ====================================================================================================================
--4a -------------------------------------------------------
--> ERROR: duplicate key value...( Key (id) = (01) already exists. )
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('01', 4025678, 3, 1402, 19);

--> ERROR: ...violates foreign key...( Key (student_id)=(402567888) is not present in table "Students".)
INSERT INTO "StudentCourseRelations" (id, student_id, course_id, year, grade) VALUES ('20', 402567888, 3, 1402, 19);

--4b -------------------------------------------------------
create table "StudentDetails"
(
    student_id  integer not null constraint "StudentDetails_pkey1" primary key constraint studentdetails_students_id_fk references "Students",
    description varchar(10)
);

insert into "StudentDetails"("student_id", "description")
select "id", 'با تجربه' from "Students"
where "id" < 3950000
AND "isGraduated" is false;

--4p --------------------------------------------------------
update "StudentCourseRelations"
set grade = (select avg(grade) from "StudentCourseRelations" )
where grade is null;

--4s --------------------------------------------------------
update "StudentCourseRelations" SR
set grade = (select avg(grade) from "StudentCourseRelations" where course_id = SR.course_id)
where grade is null;

--4j -------------------------------------------------------
update "StudentCourseRelations" SR
set grade = case
    when grade is null then (select avg(grade) from "StudentCourseRelations" where course_id = SR.course_id)
    when course_id = 1 then grade * 1.1
    when grade < 10 then 10
    else grade
end;


--5 ====================================================================================================================
--5_2 --------------------------------------------------------
select S.id, S.name, S.family, "isGraduated", major_name
from "Students" S
where S.id not in(select student_id from "StudentCourseRelations")
union
select S.id, S.name, S.family, "isGraduated", major_name
from "Students" S, "StudentCourseRelations" SCR
where S.id = SCR.student_id
and grade between 0 and 15 and grade != 11;
--or
select id, name, family, "isGraduated", major_name
from "Students"
where id not in (
    select student_id from "StudentCourseRelations") or id in (
        select student_id from "StudentCourseRelations" where grade between 0 and 15 and grade != 11);

--5_3 -------------------------------------------------------
select S.id, S.name
from "Students" s, "StudentCourseRelations" scr, "Courses" c
where s.id = scr.student_id and c.id = scr.course_id
group by S.id, S.name
having count(distinct course_id) = (select count(id) from "Courses" where id != 4);
--or
with t1(id) as (
    select S.id
    from "Students" s,
         "StudentCourseRelations" scr,
         "Courses" c
    where s.id = scr.student_id
      and c.id = scr.course_id
    and course_id !=4
    group by S.id
    having count(distinct course_id) = (select count(id) from "Courses" where id != 4)
)
select t1.id, name
from "Students", t1
where t1.id = "Students".id;
--or
select name, id
from "Students"
where id in (
    select student_id from "StudentCourseRelations" where course_id !=4 group by student_id having count(distinct course_id) = (
        select count(id) from "Courses" where id != 4)
    );

--5_4 ---------------------------------------------------------
select count(*)
from (
     select 'a'
     from "StudentCourseRelations"
     group by student_id
     having avg(grade) > (select avg(grade) from "StudentCourseRelations")
 )s;

--5_5 ---------------------------------------------------------
select 'total' status, count(*)
from "Students"
union
(
    select 'NotGraduated', count(distinct id)
    from "Students"
    where not "isGraduated"
)
union(
    select 'top', count(*) from (
        select student_id,
            count(distinct course_id)
        from "StudentCourseRelations"
        group by student_id
        having avg(grade) > (select avg(grade) from "StudentCourseRelations")
    )a
);
--or
select
(select count(id) from "Students"
    ) as total,
(select count(id) from "Students" where "isGraduated" = false
    ) as "notGraduated",
(select count(student_id)
from (
    select student_id
    from "StudentCourseRelations"
    group by student_id
    having avg(grade) > (
        select avg(grade) from "StudentCourseRelations"
        )
    ) as a) as top;

--5_6 ---------------------------------------------------------------
delete from "StudentCourseRelations"
where substring(student_id :: varchar, 1, 3) > substring(year :: varchar, 2, 4);
--or
delete from "StudentCourseRelations"
where year < (left(student_id::varchar, 3)::int + 1000);


--`\(^_^)/`--
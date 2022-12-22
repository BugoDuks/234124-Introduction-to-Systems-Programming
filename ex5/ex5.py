import json
import os


def names_of_registered_students(input_json_path, course_name):
    """
    This function returns a list of the names of the students who registered for
    the course with the name "course_name".

    :param input_json_path: Path of the students database json file.
    :param course_name: The name of the course.
    :return: List of the names of the students.
    """
    with open(input_json_path, 'r') as file_input:
        students = json.load(file_input)
    return [student["student_name"] for student in students.values() if course_name in student["registered_courses"]]


def enrollment_numbers(input_json_path, output_file_path):
    """
    This function writes all the course names and the number of enrolled
    student in ascending order to the output file in the given path.

    :param input_json_path: Path of the students database json file.
    :param output_file_path: Path of the output text file.
    """
    course_dict = {}

    with open(input_json_path, 'r') as file_input:
        data = json.load(file_input)

    for student_id in data:
        for course_name in data.get(student_id)['registered_courses']:
            course_dict.setdefault(course_name, 0)
            course_dict[course_name] += 1

    with open(output_file_path, 'w') as file_output:
        for course_name in sorted(course_dict):
            file_output.write("\"" + course_name + "\" " + str(course_dict[course_name]) + "\n")


def courses_for_lecturers(json_directory_path, output_json_path):
    """
    This function writes the courses given by each lecturer in json format.

    :param json_directory_path: Path of the semsters_data files.
    :param output_json_path: Path of the output json file.
    """
    lecturer_dict = {}

    for file_name in os.listdir(json_directory_path):
        if file_name.endswith(".json"):
            with open(os.path.join(json_directory_path, file_name)) as file_input:
                data = json.load(file_input)

            [[lecturer_dict[lecturer].append(course['course_name']) for lecturer in course['lecturers']
                if not course['course_name'] in lecturer_dict.setdefault(lecturer, [])] for course in data.values()]

    with open(output_json_path, 'w') as output_file:
        json.dump(lecturer_dict, output_file, indent=4)

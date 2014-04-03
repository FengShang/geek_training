import xml.etree.ElementTree as ET
import os
FILE_NAME="cppncss-report-guidance.xml"
SLASH="/"
THRESHOLD = 10
def parse_report():
	file_path = os.path.join(os.getcwd()+SLASH+FILE_NAME)
	if not os.path.exists(file_path):
		print "Can't find complexity report, please run the build.sh first."
	else:
		dom = ET.ElementTree(file=file_path)
		root = dom.getroot()
		print "\033[1;33mThis is the complexity of your code:\033[0m"
		for measure in root:
			print "-- Measured by: \033[1;36m" + measure.attrib['type'] + "\033[0m"
			for fragement in measure:
				if not fragement.tag in ['labels','average','sum']:
					print "  -- Name: \033[1;32m" + fragement.attrib['name'] + "\033[0m"
					print "     Effective_code_lines: \033[1;32m"+ fragement[1].text + "\033[0m"
					print "     Complexity: " + paint_by_complexity(fragement[2].text) + "\033[0m"
def paint_by_complexity(complexity):
	if int(complexity) > THRESHOLD:
		return "\033[1;31m" + complexity
	else:
		return "\033[1;32m" + complexity
if __name__ == '__main__':
	parse_report()

add_test( SanityTests.readAscFile [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build/labTreetests]==] [==[--gtest_filter=SanityTests.readAscFile]==] --gtest_also_run_disabled_tests)
set_tests_properties( SanityTests.readAscFile PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( SanityTests.indexFile [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build/labTreetests]==] [==[--gtest_filter=SanityTests.indexFile]==] --gtest_also_run_disabled_tests)
set_tests_properties( SanityTests.indexFile PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( SanityTests.indexFileALU [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build/labTreetests]==] [==[--gtest_filter=SanityTests.indexFileALU]==] --gtest_also_run_disabled_tests)
set_tests_properties( SanityTests.indexFileALU PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( OakTests.OakReadFile [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build/labTreetests]==] [==[--gtest_filter=OakTests.OakReadFile]==] --gtest_also_run_disabled_tests)
set_tests_properties( OakTests.OakReadFile PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( OakTests.OakByNorm [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build/labTreetests]==] [==[--gtest_filter=OakTests.OakByNorm]==] --gtest_also_run_disabled_tests)
set_tests_properties( OakTests.OakByNorm PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( OakTests.VoidSphereSelection [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build/labTreetests]==] [==[--gtest_filter=OakTests.VoidSphereSelection]==] --gtest_also_run_disabled_tests)
set_tests_properties( OakTests.VoidSphereSelection PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12/lab2/labTree/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( labTreetests_TESTS SanityTests.readAscFile SanityTests.indexFile SanityTests.indexFileALU OakTests.OakReadFile OakTests.OakByNorm OakTests.VoidSphereSelection)
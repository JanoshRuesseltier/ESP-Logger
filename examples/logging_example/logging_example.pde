
#include "Logger.h"

Logger logger = Logger(&Serial, "[global]", INFO);

void setup() {
  Serial.begin(115200);

  //<< streaming operator is made possible by Streaming.h from Mikal Hart
  Serial << "Hello World" << endl;

  //Simple messages coudld be logged with the level as function name
  logger.none("None Test\r\n");
  logger.error("error Test\r\n");
  logger.warning("warning Test\r\n");
  logger.info("info Test\r\n");
  logger.debug("debug Test\r\n");      //is not printed because the filter was set to INFO
  logger.verbose("verbose Test\r\n");  //is not printed because the filter was set to INFO

  Serial.println("\nYou also could print to the Serial whitout any filtering.\n");

  //There are new line version of this functions too
  logger.noneln("None Test");
  logger.errorln("error Test");
  logger.warningln("warning Test");
  logger.infoln("info Test");
  logger.debugln("debug Test");      //is not printed because the filter was set to INFO
  logger.verboseln("verbose Test");  //is not printed because the filter was set to INFO
  
  //The logger blocking the printing untill you unlock() it or use none(), error(), warning(), info(), debug() or verbose() again.
  logger.println("You should not see this.");
  logger << ("And not that either.") << endl;
  logger.unlock();
  logger.println("You should see this line.");

  //Streaming style could help you to print variables and splittet messages
  int tempInt = 404;
  logger.error("This is a big mess: ") << tempInt << endl;
  logger.info("This message part is stored in the RAM - ") << F("this part is sored in the flash.") << endl;
  logger.info() << "This is a test information" <<endl;

  //change the filter level
  logger.setLevel(ERROR);
  logger.warning("Now this shouldn't be printed!") << endl;
  logger.setLevel(DEBUG);
  logger.warning("Now this should be printed!") << endl;

  //the prefix could be disabled
  logger.setPrintPrefix(false);
  logger.info("Now you shoudn't see the prefix") << endl;
  logger.setPrintPrefix(true);
  logger.info(" <- there should be a prefix") << endl;

  //Things which you may not like
  logger.infoln("First Line") << "Second Line";  // here the new line char is set befor the streaming operator << occure
}

void loop() {
}
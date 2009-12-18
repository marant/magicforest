CXX = g++
CFLAGS = -Wall -W -g
DEFINE = -DDEBUG

magicforest: CGame.o CGameCharacter.o CGameItem.o CLocation.o IEvent.o \
						 CBattleEvent.o CEndEvent.o\
						 IGameObject.o IInteractionEssentials.o IPhysicalInteractions.o
	$(CXX) $(CFLAGS) $(DEFINE) CGame.o CGameCharacter.o CGameItem.o CLocation.o IEvent.o \
				IGameObject.o IInteractionEssentials.o IPhysicalInteractions.o CBattleEvent.o \
				CEndEvent.o \
				magicforest.cpp -o magicforest

CGame.o: CGame.cpp CGame.h \
				 IEvent.h \
				 CGameCharacter.h
	$(CXX) $(CFLAGS)  $(DEFINE) CGame.cpp -c -o CGame.o

CGameCharacter.o: CGameCharacter.cpp CGameCharacter.h \
									IGameObject.h \
									IPhysicalInteractions.h \
									IInteractionEssentials.h 
	$(CXX) $(CFLAGS) $(DEFINE)  CGameCharacter.cpp -c -o CGameCharacter.o

CGameItem.o: CGameItem.cpp CGameItem.h \
						 IGameObject.h
	$(CXX) $(CFLAGS) $(DEFINE)  CGameItem.cpp -c -o CGameItem.o

CLocation.o: CLocation.cpp CLocation.h \
						 IEvent.h
	$(CXX) $(CFLAGS) $(DEFINE)  CLocation.cpp -c -o CLocation.o

CBattleEvent.o: CBattleEvent.h CBattleEvent.cpp \
								CGameCharacter.h
	$(CXX) $(CFLAGS) $(DEFINE) CBattleEvent.cpp -c -o CBattleEvent.o

CEndEvent.o: CEndEvent.h CEndEvent.cpp \
						 IEvent.h
	$(CXX) $(CFLAGS) $(DEFINE) CEndEvent.cpp -c -o CEndEvent.o

IEvent.o: IEvent.h IEvent.cpp \
					IGameObject.h \
					CLocation.h \
					CGameCharacter.h
	$(CXX) $(CFLAGS) $(DEFINE)  IEvent.cpp -c -o IEvent.o

IGameObject.o: IGameObject.cpp IGameObject.h \
							 IEvent.h \
							 CLocation.h
	$(CXX) $(CFLAGS) $(DEFINE)  IGameObject.cpp -c -o IGameObject.o

IInteractionEssentials.o: IInteractionEssentials.cpp IInteractionEssentials.h
	$(CXX) $(CFLAGS) $(DEFINE)  IInteractionEssentials.cpp -c -o IInteractionEssentials.o

IPhysicalInteractions.o: IPhysicalInteractions.cpp IPhysicalInteractions.h \
												 CGameCharacter.h
	$(CXX) $(CFLAGS) $(DEFINE)  IPhysicalInteractions.cpp -c -o IPhysicalInteractions.o

clean:
	rm *.o

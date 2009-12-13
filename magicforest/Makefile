CXX = g++
CFLAGS = -Wall -W -g

magicforest: CGame.o CGameCharacter.o CGameItem.o CLocation.o IEvent.o \
						 IGameObject.o IInteractionEssentials.o IPhysicalInteractions.o
	$(CXX) $(CFLAGS) CGame.o CGameCharacter.o CGameItem.o CLocation.o IEvent.o \
				IGameObject.o IInteractionEssentials.o IPhysicalInteractions.o \
				magicforest.cpp -o magicforest

CGame.o: CGame.cpp CGame.h \
				 IEvent.h \
				 CGameCharacter.h
	$(CXX) $(CFLAGS) CGame.cpp -c -o CGame.o

CGameCharacter.o: CGameCharacter.cpp CGameCharacter.h \
									IGameObject.h \
									IPhysicalInteractions.h \
									IInteractionEssentials.h 
	$(CXX) $(CFLAGS) CGameCharacter.cpp -c -o CGameCharacter.o

CGameItem.o: CGameItem.cpp CGameItem.h \
						 IGameObject.h
	$(CXX) $(CFLAGS) CGameItem.cpp -c -o CGameItem.o

CLocation.o: CLocation.cpp CLocation.h \
						 IEvent.h
	$(CXX) $(CFLAGS) CLocation.cpp -c -o CLocation.o

IEvent.o: IEvent.h IEvent.cpp \
					IGameObject.h \
					CLocation.h \
					CGameCharacter.h
	$(CXX) $(CFLAGS) IEvent.cpp -c -o IEvent.o

IGameObject.o: IGameObject.cpp IGameObject.h \
							 IEvent.h \
							 CLocation.h
	$(CXX) $(CFLAGS) IGameObject.cpp -c -o IGameObject.o

IInteractionEssentials.o: IInteractionEssentials.cpp IInteractionEssentials.h
	$(CXX) $(CFLAGS) IInteractionEssentials.cpp -c -o IInteractionEssentials.o

IPhysicalInteractions.o: IPhysicalInteractions.cpp IPhysicalInteractions.h \
												 CGameCharacter.h
	$(CXX) $(CFLAGS) IPhysicalInteractions.cpp -c -o IPhysicalInteractions.o

clean:
	rm *.o

      subroutine nexts
     +	(RWK, IWK, iinit, scalname, idone,IERR )
c these routine reads the (sub)grid coordinates

      INTEGER IERR
      CHARACTER*20 scalname
      REAL RWK
      INTEGER IWK
      INTEGER iinit, idone
      
      DIMENSION RWK(70000000)
      DIMENSION IWK(5000000)

      LOGICAL INIT, DONE

      DONE = .FALSE.
      idone = 0

      INIT = .TRUE.
      IF ( iinit .EQ. 1 ) GOTO 60
      INIT = .FALSE.

      
C     Find Which Scalar Fields are Present in Memory
60    CALL TRNXTS (RWK, IWK, INIT, scalname, DONE, IERR)
      IF (IERR .GT. 0) GOTO 999

      IF ( DONE .EQV. .FALSE. ) GOTO 999 
      idone = 1

999   CONTINUE

      END






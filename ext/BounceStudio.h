/*
 * Copyright (c) 1999-2006 BoogieTools, Inc. All rights reserved
 *
 */

#ifndef BOUNCESTUDIO_H
#define BOUNCESTUDIO_H

/* constants returned by BSBOUNCECHECK */
#define BS_UNDETERMINED            0 /* Undetermined */
#define BS_HARD                   10 /* HARD BOUNCE */
#define BS_SOFT_GENERAL           20 /* SOFT BOUNCE - General */
#define BS_SOFT_DNSFAILURE        21 /* SOFT BOUNCE - Dns Failure */
#define BS_SOFT_MAILBOXFULL       22 /* SOFT BOUNCE - Mailbox Full */
#define BS_SOFT_MESSAGETOBIG      23 /* SOFT BOUNCE - Message Size Too Large */
#define BS_NOEMAIL                30 /* BOUNCE - email address could not be retrieved. */
#define BS_GENERAL                40 /* GENERAL BOUNCE */
#define BS_MAILBLOCK_GENERAL      50 /* MAIL BLOCK - General */
#define BS_MAILBLOCK_SPAMMER      51 /* MAIL BLOCK - Known Spammer */
#define BS_MAILBLOCK_SPAMDETECTED 52 /* MAIL BLOCK - Spam Content Detected */
#define BS_MAILBLOCK_ATTACHMENT   53 /* MAIL BLOCK - Attachment Detected */
#define BS_MAILBLOCK_RELAYDENIED  54 /* MAIL BLOCK - Relay Denied */
#define BS_AUTOREPLY              60 /* AUTO REPLY */
#define BS_TRANSIENT              70 /* TRANSIENT BOUNCE */
#define BS_SUBSCRIBE              80 /* SUBSCRIBE REQUEST */
#define BS_UNSUBSCRIBE            90 /* UNSUBSCRIBE REQUEST */
#define BS_CHALLENGERESPONSE     100 /* CHALLENGE-RESPONSE MESSAGE */

#ifdef __cplusplus
extern "C" {
#endif

/* Initialize The BounceStudio API Engine */
int bsBounceStudio_init();
int bsBounceCheck(char *sMessageText, char **sEmailAddress, 
                  char *sEmailIgnoreList, char *sKey);
void bsGetHeader(char *sMessageText, char **sReturn);
void bsGetBody(char *sMessageText, char **sReturn);
void bsGetSubject(char *sMessageText, char **sReturn);
void bsGetToAddress(char *sMessageText, char **sReturn);
void bsGetToFriendlyName(char *sMessageText, char **sReturn);
void bsGetReplyToAddress(char *sMessageText, char **sReturn);
void bsGetReplyToFriendlyName(char *sMessageText, char **sReturn);
void bsGetFromAddress(char *sMessageText, char **sReturn);
void bsGetFromFriendlyName(char *sMessageText, char **sReturn);
void bsGetCustomHeader(char *sMessageText, char **sReturn,
                       char *sCustomHeader);
void bsGetOrigCustomHeader(char *sMessageText, char **sReturn,
                           char *sCustomHeader);

#ifdef __cplusplus
}
#endif

#endif

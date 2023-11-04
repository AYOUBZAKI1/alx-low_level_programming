{"payload":{"allShortcutsEnabled":false,"fileTree":{"0x1A-hash_tables":{"items":[{"name":".gitignore","path":"0x1A-hash_tables/.gitignore","contentType":"file"},{"name":"0-hash_table_create.c","path":"0x1A-hash_tables/0-hash_table_create.c","contentType":"file"},{"name":"1-djb2.c","path":"0x1A-hash_tables/1-djb2.c","contentType":"file"},{"name":"100-sorted_hash_table.c","path":"0x1A-hash_tables/100-sorted_hash_table.c","contentType":"file"},{"name":"2-key_index.c","path":"0x1A-hash_tables/2-key_index.c","contentType":"file"},{"name":"3-hash_table_set.c","path":"0x1A-hash_tables/3-hash_table_set.c","contentType":"file"},{"name":"4-hash_table_get.c","path":"0x1A-hash_tables/4-hash_table_get.c","contentType":"file"},{"name":"5-hash_table_print.c","path":"0x1A-hash_tables/5-hash_table_print.c","contentType":"file"},{"name":"6-hash_table_delete.c","path":"0x1A-hash_tables/6-hash_table_delete.c","contentType":"file"},{"name":"README.md","path":"0x1A-hash_tables/README.md","contentType":"file"},{"name":"d","path":"0x1A-hash_tables/d","contentType":"file"},{"name":"hash_tables.h","path":"0x1A-hash_tables/hash_tables.h","contentType":"file"},{"name":"sht","path":"0x1A-hash_tables/sht","contentType":"file"}],"totalCount":13},"":{"items":[{"name":"0x00-hello_world","path":"0x00-hello_world","contentType":"directory"},{"name":"0x01-variables_if_else_while","path":"0x01-variables_if_else_while","contentType":"directory"},{"name":"0x02-functions_nested_loops","path":"0x02-functions_nested_loops","contentType":"directory"},{"name":"0x03-debugging","path":"0x03-debugging","contentType":"directory"},{"name":"0x04-more_functions_nested_loops","path":"0x04-more_functions_nested_loops","contentType":"directory"},{"name":"0x05-pointers_arrays_strings","path":"0x05-pointers_arrays_strings","contentType":"directory"},{"name":"0x06-pointers_arrays_strings","path":"0x06-pointers_arrays_strings","contentType":"directory"},{"name":"0x07-pointers_arrays_strings","path":"0x07-pointers_arrays_strings","contentType":"directory"},{"name":"0x08-recursion","path":"0x08-recursion","contentType":"directory"},{"name":"0x09-static_libraries","path":"0x09-static_libraries","contentType":"directory"},{"name":"0x0A-argc_argv","path":"0x0A-argc_argv","contentType":"directory"},{"name":"0x0B-malloc_free","path":"0x0B-malloc_free","contentType":"directory"},{"name":"0x0C-more_malloc_free","path":"0x0C-more_malloc_free","contentType":"directory"},{"name":"0x0D-preprocessor","path":"0x0D-preprocessor","contentType":"directory"},{"name":"0x0E-structures_typedef","path":"0x0E-structures_typedef","contentType":"directory"},{"name":"0x0F-function_pointers","path":"0x0F-function_pointers","contentType":"directory"},{"name":"0x10-variadic_functions","path":"0x10-variadic_functions","contentType":"directory"},{"name":"0x12-singly_linked_lists","path":"0x12-singly_linked_lists","contentType":"directory"},{"name":"0x13-more_singly_linked_lists","path":"0x13-more_singly_linked_lists","contentType":"directory"},{"name":"0x14-bit_manipulation","path":"0x14-bit_manipulation","contentType":"directory"},{"name":"0x15-file_io","path":"0x15-file_io","contentType":"directory"},{"name":"0x17-doubly_linked_lists","path":"0x17-doubly_linked_lists","contentType":"directory"},{"name":"0x18-dynamic_libraries","path":"0x18-dynamic_libraries","contentType":"directory"},{"name":"0x1A-hash_tables","path":"0x1A-hash_tables","contentType":"directory"},{"name":"README.md","path":"README.md","contentType":"file"}],"totalCount":25}},"fileTreeProcessingTime":6.170483,"foldersToFetch":[],"reducedMotionEnabled":null,"repo":{"id":602626757,"defaultBranch":"main","name":"alx-low_level_programming","ownerLogin":"hamzahdili2001","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2023-02-16T15:57:19.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/61630679?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"main","listCacheKey":"v0:1676563248.540381","canEdit":false,"refType":"branch","currentOid":"f8250dfa3141b10609fc9f4ffcc2b37932520e00"},"path":"0x1A-hash_tables/3-hash_table_set.c","currentUser":null,"blob":{"rawLines":["#include \"hash_tables.h\"","#include <string.h>","#define True 1","#define False 0","/**"," * hash_table_set -  function that adds an element to the hash table."," * @ht: is a pointer to the hash table."," * @key: is the key."," * @value: is the value."," * Return: True or False - based on the code.","*/","","int hash_table_set(hash_table_t *ht, const char *key, const char *value)","{","\thash_node_t *new_node, *tmp;","\tunsigned long int i;","","\tif (ht == NULL || key == NULL || *key == '\\0' || value == NULL)","\t\treturn (False);","\ti = key_index((unsigned char *)key, ht->size);","\ttmp = ht->array[i];","\twhile (tmp != NULL)","\t{","\t\tif (strcmp(tmp->key, key) == 0)","\t\t{","\t\t\tfree(tmp->value);","\t\t\ttmp->value = strdup(value);","\t\t\tif (tmp->value == NULL)","\t\t\t\treturn (False);","\t\t\treturn (True);","\t\t}","\t\ttmp = tmp->next;","\t}","\tnew_node =  malloc(sizeof(hash_node_t));","\tif (new_node == NULL)","\t\treturn (False);","","\tnew_node->key = strdup(key);","\tif (new_node->key == NULL)","\t{","\t\tfree(new_node);","\t\treturn (False);","\t}","\tnew_node->value = strdup(value);","\tif (new_node->value == NULL)","\t{","\t\tfree(new_node->key);","\t\tfree(new_node);","\t\treturn (False);","\t}","\tnew_node->next = ht->array[i];","\tht->array[i] = new_node;","\treturn (True);","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":24,"cssClass":"pl-s"}],[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":19,"cssClass":"pl-s"}],[{"start":0,"end":7,"cssClass":"pl-k"},{"start":8,"end":12,"cssClass":"pl-s1"}],[{"start":0,"end":7,"cssClass":"pl-k"},{"start":8,"end":13,"cssClass":"pl-s1"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":69,"cssClass":"pl-c"}],[{"start":0,"end":39,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":24,"cssClass":"pl-c"}],[{"start":0,"end":45,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[],[{"start":0,"end":3,"cssClass":"pl-smi"},{"start":4,"end":18,"cssClass":"pl-en"},{"start":19,"end":31,"cssClass":"pl-smi"},{"start":32,"end":33,"cssClass":"pl-c1"},{"start":33,"end":35,"cssClass":"pl-s1"},{"start":37,"end":42,"cssClass":"pl-k"},{"start":43,"end":47,"cssClass":"pl-smi"},{"start":48,"end":49,"cssClass":"pl-c1"},{"start":49,"end":52,"cssClass":"pl-s1"},{"start":54,"end":59,"cssClass":"pl-k"},{"start":60,"end":64,"cssClass":"pl-smi"},{"start":65,"end":66,"cssClass":"pl-c1"},{"start":66,"end":71,"cssClass":"pl-s1"}],[],[{"start":1,"end":12,"cssClass":"pl-smi"},{"start":13,"end":14,"cssClass":"pl-c1"},{"start":14,"end":22,"cssClass":"pl-s1"},{"start":24,"end":25,"cssClass":"pl-c1"},{"start":25,"end":28,"cssClass":"pl-s1"}],[{"start":1,"end":18,"cssClass":"pl-smi"},{"start":15,"end":18,"cssClass":"pl-smi"},{"start":19,"end":20,"cssClass":"pl-s1"}],[],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":7,"cssClass":"pl-s1"},{"start":8,"end":10,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-c1"},{"start":16,"end":18,"cssClass":"pl-c1"},{"start":19,"end":22,"cssClass":"pl-s1"},{"start":23,"end":25,"cssClass":"pl-c1"},{"start":26,"end":30,"cssClass":"pl-c1"},{"start":31,"end":33,"cssClass":"pl-c1"},{"start":34,"end":35,"cssClass":"pl-c1"},{"start":35,"end":38,"cssClass":"pl-s1"},{"start":39,"end":41,"cssClass":"pl-c1"},{"start":42,"end":46,"cssClass":"pl-c1"},{"start":47,"end":49,"cssClass":"pl-c1"},{"start":50,"end":55,"cssClass":"pl-s1"},{"start":56,"end":58,"cssClass":"pl-c1"},{"start":59,"end":63,"cssClass":"pl-c1"}],[{"start":2,"end":8,"cssClass":"pl-k"},{"start":10,"end":15,"cssClass":"pl-s1"}],[{"start":1,"end":2,"cssClass":"pl-s1"},{"start":3,"end":4,"cssClass":"pl-c1"},{"start":5,"end":14,"cssClass":"pl-en"},{"start":16,"end":29,"cssClass":"pl-smi"},{"start":25,"end":29,"cssClass":"pl-smi"},{"start":30,"end":31,"cssClass":"pl-c1"},{"start":32,"end":35,"cssClass":"pl-s1"},{"start":37,"end":39,"cssClass":"pl-s1"},{"start":39,"end":41,"cssClass":"pl-c1"},{"start":41,"end":45,"cssClass":"pl-c1"}],[{"start":1,"end":4,"cssClass":"pl-s1"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":7,"end":9,"cssClass":"pl-s1"},{"start":9,"end":11,"cssClass":"pl-c1"},{"start":11,"end":16,"cssClass":"pl-c1"},{"start":17,"end":18,"cssClass":"pl-s1"}],[{"start":1,"end":6,"cssClass":"pl-k"},{"start":8,"end":11,"cssClass":"pl-s1"},{"start":12,"end":14,"cssClass":"pl-c1"},{"start":15,"end":19,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":12,"cssClass":"pl-en"},{"start":13,"end":16,"cssClass":"pl-s1"},{"start":16,"end":18,"cssClass":"pl-c1"},{"start":18,"end":21,"cssClass":"pl-c1"},{"start":23,"end":26,"cssClass":"pl-s1"},{"start":28,"end":30,"cssClass":"pl-c1"},{"start":31,"end":32,"cssClass":"pl-c1"}],[],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":11,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":13,"end":18,"cssClass":"pl-c1"}],[{"start":3,"end":6,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"},{"start":8,"end":13,"cssClass":"pl-c1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":16,"end":22,"cssClass":"pl-en"},{"start":23,"end":28,"cssClass":"pl-s1"}],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":10,"cssClass":"pl-s1"},{"start":10,"end":12,"cssClass":"pl-c1"},{"start":12,"end":17,"cssClass":"pl-c1"},{"start":18,"end":20,"cssClass":"pl-c1"},{"start":21,"end":25,"cssClass":"pl-c1"}],[{"start":4,"end":10,"cssClass":"pl-k"},{"start":12,"end":17,"cssClass":"pl-s1"}],[{"start":3,"end":9,"cssClass":"pl-k"},{"start":11,"end":15,"cssClass":"pl-s1"}],[],[{"start":2,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":11,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":13,"end":17,"cssClass":"pl-c1"}],[],[{"start":1,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":13,"end":19,"cssClass":"pl-en"},{"start":20,"end":26,"cssClass":"pl-k"},{"start":27,"end":38,"cssClass":"pl-s1"}],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":13,"cssClass":"pl-s1"},{"start":14,"end":16,"cssClass":"pl-c1"},{"start":17,"end":21,"cssClass":"pl-c1"}],[{"start":2,"end":8,"cssClass":"pl-k"},{"start":10,"end":15,"cssClass":"pl-s1"}],[],[{"start":1,"end":9,"cssClass":"pl-s1"},{"start":9,"end":11,"cssClass":"pl-c1"},{"start":11,"end":14,"cssClass":"pl-c1"},{"start":15,"end":16,"cssClass":"pl-c1"},{"start":17,"end":23,"cssClass":"pl-en"},{"start":24,"end":27,"cssClass":"pl-s1"}],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":13,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":15,"end":18,"cssClass":"pl-c1"},{"start":19,"end":21,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-c1"}],[],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":15,"cssClass":"pl-s1"}],[{"start":2,"end":8,"cssClass":"pl-k"},{"start":10,"end":15,"cssClass":"pl-s1"}],[],[{"start":1,"end":9,"cssClass":"pl-s1"},{"start":9,"end":11,"cssClass":"pl-c1"},{"start":11,"end":16,"cssClass":"pl-c1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":25,"cssClass":"pl-en"},{"start":26,"end":31,"cssClass":"pl-s1"}],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":13,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":15,"end":20,"cssClass":"pl-c1"},{"start":21,"end":23,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-c1"}],[],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":15,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":17,"end":20,"cssClass":"pl-c1"}],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":15,"cssClass":"pl-s1"}],[{"start":2,"end":8,"cssClass":"pl-k"},{"start":10,"end":15,"cssClass":"pl-s1"}],[],[{"start":1,"end":9,"cssClass":"pl-s1"},{"start":9,"end":11,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-c1"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":18,"end":20,"cssClass":"pl-s1"},{"start":20,"end":22,"cssClass":"pl-c1"},{"start":22,"end":27,"cssClass":"pl-c1"},{"start":28,"end":29,"cssClass":"pl-s1"}],[{"start":1,"end":3,"cssClass":"pl-s1"},{"start":3,"end":5,"cssClass":"pl-c1"},{"start":5,"end":10,"cssClass":"pl-c1"},{"start":11,"end":12,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":16,"end":24,"cssClass":"pl-s1"}],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":13,"cssClass":"pl-s1"}],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/hamzahdili2001/alx-low_level_programming/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null,"repoAlertsPath":"/hamzahdili2001/alx-low_level_programming/security/dependabot","repoSecurityAndAnalysisPath":"/hamzahdili2001/alx-low_level_programming/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"3-hash_table_set.c","displayUrl":"https://github.com/hamzahdili2001/alx-low_level_programming/blob/main/0x1A-hash_tables/3-hash_table_set.c?raw=true","headerInfo":{"blobSize":"1.13 KB","deleteInfo":{"deleteTooltip":"You must be signed in to make or propose changes"},"editInfo":{"editTooltip":"You must be signed in to make or propose changes"},"ghDesktopPath":"https://desktop.github.com","gitLfsPath":null,"onBranch":true,"shortPath":"292a6e9","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fhamzahdili2001%2Falx-low_level_programming%2Fblob%2Fmain%2F0x1A-hash_tables%2F3-hash_table_set.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"54","truncatedSloc":"51"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"loggedIn":false,"newDiscussionPath":"/hamzahdili2001/alx-low_level_programming/discussions/new","newIssuePath":"/hamzahdili2001/alx-low_level_programming/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/hamzahdili2001/alx-low_level_programming/blob/main/0x1A-hash_tables/3-hash_table_set.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/hamzahdili2001/alx-low_level_programming/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"rawBlobUrl":"https://github.com/hamzahdili2001/alx-low_level_programming/raw/main/0x1A-hash_tables/3-hash_table_set.c","renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"hamzahdili2001","repoName":"alx-low_level_programming","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"True","kind":"macro","identStart":53,"identEnd":57,"extentStart":45,"extentEnd":60,"fullyQualifiedName":"True","identUtf16":{"start":{"lineNumber":2,"utf16Col":8},"end":{"lineNumber":2,"utf16Col":12}},"extentUtf16":{"start":{"lineNumber":2,"utf16Col":0},"end":{"lineNumber":3,"utf16Col":0}}},{"name":"False","kind":"macro","identStart":68,"identEnd":73,"extentStart":60,"extentEnd":76,"fullyQualifiedName":"False","identUtf16":{"start":{"lineNumber":3,"utf16Col":8},"end":{"lineNumber":3,"utf16Col":13}},"extentUtf16":{"start":{"lineNumber":3,"utf16Col":0},"end":{"lineNumber":4,"utf16Col":0}}},{"name":"hash_table_set","kind":"function","identStart":290,"identEnd":304,"extentStart":290,"extentEnd":358,"fullyQualifiedName":"hash_table_set","identUtf16":{"start":{"lineNumber":12,"utf16Col":4},"end":{"lineNumber":12,"utf16Col":18}},"extentUtf16":{"start":{"lineNumber":12,"utf16Col":4},"end":{"lineNumber":12,"utf16Col":72}}}]}},"copilotInfo":null,"copilotAccessAllowed":false,"csrf_tokens":{"/hamzahdili2001/alx-low_level_programming/branches":{"post":"DAK3ugFdPkOKhH_VKnY0dPfTC6EDpoJyTVCsX2JBbzmYO6w9oGqaE63_7pWl5RG2ToNMLZWi7BycI1bmxQhfIw"},"/repos/preferences":{"post":"R0huukk_l657lqgelp2mhcO_UJAqPuYbRYRPwYQhnKajaXKB0mQYApo6os1mFOolBOynuPIY-ZaM23QCs9cdwA"}}},"title":"alx-low_level_programming/0x1A-hash_tables/3-hash_table_set.c at main · hamzahdili2001/alx-low_level_programming"}
 public List<ProjectListResponse> getProjectListByDesigner(String designerName) {
        String designerNameLower = designerName.toLowerCase();
        List<ProjectListResponse> projectListResponses = new ArrayList<>();
        Designer designer = designerRepository.findByDesignerName(designerName).orElseThrow(() -> new IllegalArgumentException("해당 디자이너는 없습니다."));
        final String designerCode = designer.getDesignerCode();
        List<Project> project = projectRepository.findByDesignerCode(designerCode);
        final String projectList = project.getProjectList();
        final String[] projectListSplit = projectList.split(",");
